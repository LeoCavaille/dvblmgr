#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "ptr/multiplex.hpp"
#include "ptr/machine.hpp"
#include "ptr/configuration.hpp"

#include <boost/asio/ip/address.hpp>
#include <yaml-cpp/yaml.h>
#include <string>
#include <vector>
#include <mutex>
#include <memory>

class Configuration : public std::enable_shared_from_this<Configuration> {
public:
  Configuration(const std::string &filename);
  void load();
  void load(const YAML::Node &configParsed);
  void save();

  void machineSetConnectedFlag(const boost::asio::ip::address &ip,
                               const bool &status);

  std::vector<MachinePtr> getMachines() const {
    return machines_;
  };
  std::vector<MultiplexPtr> getMultiplexs() const {
    return multiplexs_;
  };

  bool operator==(const Configuration &rhs) const;

  bool hasChanged();

  // TODO : be more restrictive
  friend class BroadcastListGenerator;

private:
  ConfigurationPtr getSelfPtr();
  void parse();
  void parseMultiplexs();
  void parseMachines();

  void check();
  void checkChannelDupes();

  std::string filename_;
  YAML::Node config_;

  std::vector<MultiplexPtr> multiplexs_;
  std::vector<MachinePtr> machines_;

protected:
  bool hasChanged_;
  std::mutex mChange_;
};

#endif /* CONFIGURATION_H_ */
