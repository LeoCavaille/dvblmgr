#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "multiplex_ptr.h"
#include "server_ptr.h"

#include <yaml-cpp/yaml.h>
#include <string>

class Configuration {
public:
  Configuration(const std::string &filename);
  void load();

private:
  void parse();
  void parseMultiplexs();
  void parseServers();

  std::string filename_;
  YAML::Node config_;

  std::vector<MultiplexPtr> multiplexs_;
  std::vector<ServerPtr> servers_;


};

#endif /* CONFIGURATION_H_ */
