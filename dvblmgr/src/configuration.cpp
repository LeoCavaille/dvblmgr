#include "configuration.hpp"

#include "multiplextnt.hpp"
#include "multiplexsat.hpp"
#include "machine.hpp"

#include "configuration_exceptions.hpp"

#include <iostream>
#include <fstream>
#include <time.h>
#include <sys/stat.h>

#define DEFAULT_CONFIG "/etc/dvblmgr/dvblmgr.conf"

Configuration::Configuration(const std::string &filename)
    : filename_(filename), hasChanged_(true) {}

void Configuration::load() {
  if (filename_.empty()) {
    filename_ = DEFAULT_CONFIG;
  }

  std::cerr << "INFO: Loading config file " << filename_ << std::endl;

  // Check the file existence
  struct stat buffer;
  if (stat(filename_.c_str(), &buffer) != 0) {
    std::cerr
        << "WARNING: config file " << filename_
        << " does not exist, creating an empty one (is it what you want ?)"
        << std::endl;
    save();
    return;
  }

  config_ = YAML::LoadFile(filename_);
  parse();
}

void Configuration::load(const YAML::Node &configParsed) {
  config_ = configParsed;
  parse();
}

void Configuration::save() {
  config_.reset();

  for (auto const &m : multiplexs_) {
    MultiplexSatPtr psat = std::dynamic_pointer_cast<MultiplexSat>(m);
    if (psat != nullptr) {
      config_["multiplexs"]
          .push_back(YAML::convert<MultiplexSatPtr>::encode(psat));
      continue;
    }

    MultiplexTntPtr ptnt = std::dynamic_pointer_cast<MultiplexTnt>(m);
    if (ptnt != nullptr) {
      config_["multiplexs"]
          .push_back(YAML::convert<MultiplexTntPtr>::encode(ptnt));
      continue;
    }
  }

  for (auto const &m : machines_) {
    config_["machines"].push_back(YAML::convert<MachinePtr>::encode(m));
  }

  std::ofstream configFile(filename_);
  if (configFile.fail()) {
    throw ConfigurationFileUnreachable(filename_);
  }

  time_t curtime;
  struct tm *loctime;
  curtime = time(NULL);
  loctime = localtime(&curtime);

  configFile << "# Configuration generated by dvbmlgr " << asctime(loctime)
             << "# Do not edit manaully unless you know what you are doing"
             << "\n\n";

  // If there is nothing to output, skip YAML emitting
  // e.g. when we want to create an empty file
  if (!config_.IsNull()) {
    YAML::Emitter out;
    configFile << config_;
  }
  configFile.close();

  std::cerr << "INFO: Configuration saved" << std::endl;
  hasChanged_ = true;
}

void Configuration::machineSetConnectedFlag(const boost::asio::ip::address &ip,
                                            const bool &status) {
  std::string ipConnected(ip.to_string());
  for (auto &m : machines_) {
    if (m->getIP() == ipConnected) {
      assert(m->isConnected() == !status);
      m->setConnected(status);
      return;
    }
  }
  // If we reached this line, the machine was not found in machines_
  throw ConfigurationMachineUnauthorized(ip.to_string());
}

bool Configuration::operator==(const Configuration &rhs) const {
  // TODO
  return true;
}

void Configuration::parse() {
  parseMultiplexs();
  parseMachines();
}

void Configuration::parseMultiplexs() {
  if (!config_["multiplexs"] || !config_["multiplexs"].IsSequence()) {
    std::cerr << "WARNING: no multiplexs defined in the configuration"
              << std::endl;
    return;
  }
  for (auto const &m : config_["multiplexs"]) {
    std::string type = Multiplex::getType(m);
    if (type == "TNT") {
      MultiplexTntPtr mPtr = std::make_shared<MultiplexTnt>();
      YAML::convert<MultiplexTntPtr>::decode(m, mPtr);
      multiplexs_.push_back(mPtr);
    } else if (type == "SAT") {
      MultiplexSatPtr mPtr = std::make_shared<MultiplexSat>();
      YAML::convert<MultiplexSatPtr>::decode(m, mPtr);
      multiplexs_.push_back(mPtr);
    } else {
      std::cerr << "ERROR: multiplex type MUST be tnt or sat" << std::endl;
    }
  }
}

void Configuration::parseMachines() {
  if (!config_["machines"] || !config_["machines"].IsSequence()) {
    std::cerr << "WARNING: no machines defined in the configuration"
              << std::endl;
    return;
  }
  for (auto const &m : config_["machines"]) {
    MachinePtr mPtr = std::make_shared<Machine>();
    YAML::convert<MachinePtr>::decode(m, mPtr);
    machines_.push_back(mPtr);
  }
}

void Configuration::check() { checkChannelDupes(); }

void Configuration::checkChannelDupes() {}

bool Configuration::hasChanged() {
  mChange_.lock();
  bool b = hasChanged_;
  mChange_.unlock();
  return b;
}

ConfigurationPtr Configuration::getSelfPtr() { return shared_from_this(); }
