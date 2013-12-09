#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "multiplex_ptr.h"
#include "machine_ptr.h"

#include <yaml-cpp/yaml.h>
#include <string>
#include <vector>

class Configuration {
public:
  Configuration(const std::string &filename);
  void load();
  void load(const YAML::Node& configParsed);
  void save();

  bool operator==(const Configuration& rhs) const;

private:
  void parse();
  void parseMultiplexs();
  void parseMachines();

  void check();
  void checkChannelDupes();

  std::string filename_;
  YAML::Node config_;

  std::vector<MultiplexPtr> multiplexs_;
  std::vector<MachinePtr> machines_;


};

#endif /* CONFIGURATION_H_ */
