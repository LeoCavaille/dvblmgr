#include "configuration.hpp"

#include "multiplextnt.h"
#include "multiplexsat.h"
#include "server.h"

#include <iostream>

#define DEFAULT_CONFIG "/etc/dvblmgr/dvblmgr.conf"

Configuration::Configuration(const std::string &filename)
    : filename_(filename) {}

void Configuration::load() {
  if (filename_.empty()) {
    filename_ = DEFAULT_CONFIG;
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

  for (auto const &s : servers_) {
    config_["servers"].push_back(YAML::convert<ServerPtr>::encode(s));
  }

  YAML::Emitter out;
  out << config_;
  std::cout << out.c_str() << std::endl;
}

bool Configuration::operator==(const Configuration &rhs) const {
  // TODO
  return true;
}

void Configuration::parse() {
  parseMultiplexs();
  parseServers();
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

void Configuration::parseServers() {
  if (!config_["servers"] || !config_["servers"].IsSequence()) {
    std::cerr << "WARNING: no servers defined in the configuration"
              << std::endl;
    return;
  }
  for (auto const &s : config_["servers"]) {
    ServerPtr sPtr = std::make_shared<Server>();
    YAML::convert<ServerPtr>::decode(s, sPtr);
    servers_.push_back(sPtr);
  }
}

void Configuration::check() { checkChannelDupes(); }

void Configuration::checkChannelDupes() {}
