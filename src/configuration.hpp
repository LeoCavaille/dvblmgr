#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "multiplex_ptr.h"
#include "server_ptr.h"

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
  void parseServers();

  void check();
  void checkChannelDupes();

  std::string filename_;
  YAML::Node config_;

  std::vector<MultiplexPtr> multiplexs_;
  std::vector<ServerPtr> servers_;


};

#endif /* CONFIGURATION_H_ */
