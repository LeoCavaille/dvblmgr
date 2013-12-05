#include "antenna_yaml.h"
#include "antenna.h"

YAML::Node YAML::convert<AntennaPtr>::encode(const AntennaPtr &rhs) {
  Node node;
  node["name"] = rhs->name_;

  return node;
}

bool YAML::convert<AntennaPtr>::decode(const YAML::Node &node, AntennaPtr &rhs) {
  rhs->name_ = node["name"].as<std::string>();

  return true;
}