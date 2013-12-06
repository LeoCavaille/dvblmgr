#include "multiplex_yaml.h"
#include "multiplex.h"

#include "antenna_yaml.h"
#include "broadcasttype_yaml.h"


YAML::Node YAML::convert<MultiplexPtr>::encode(const MultiplexPtr &rhs) {
  Node node;
  node["name"] = rhs->name_;
  node["frequency"] = rhs->frequency_;
  node["priority"] = rhs->priority_;

  return node;
}

bool YAML::convert<MultiplexPtr>::decode(const YAML::Node &node, MultiplexPtr &rhs) {
  rhs->name_ = node["name"].as<std::string>();
  rhs->frequency_ = node["frequency"].as<unsigned int>();
  rhs->priority_ = node["priority"].as<unsigned int>();

  rhs->antennaPtr_ = node["antenna"].as<AntennaPtr>();
  rhs->broadcastTypePtr_ = node["broadcastType"].as<BroadcastTypePtr>();

  return true;
}