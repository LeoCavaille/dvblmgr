#include "multiplextnt.h"
#include "multiplextnt_yaml.h"

YAML::Node YAML::convert<MultiplexTnt>::encode(const MultiplexPtr &rhs) {
  Node node;
  return node;
}

bool YAML::convert<MultiplexTnt>::decode(const YAML::Node &node, MultiplexPtr &rhs) {
  YAML::convert<MultiplexPtr>::decode(node, rhs);

  // Then TNT specific parsing
  rhs->bandwidth_ = node["bandwidth"].as<unsigned int>();

  return true;
}