#include "multiplextnt.h"
#include "multiplextnt_yaml.h"

YAML::Node YAML::convert<MultiplexTntPtr>::encode(const MultiplexTntPtr &rhs) {
  Node node;
  return node;
}

bool YAML::convert<MultiplexTntPtr>::decode(const YAML::Node &node, MultiplexTntPtr &rhs) {
  YAML::convert<MultiplexPtr>::decode(node, rhs);

  // Then TNT specific parsing
  rhs->bandwidth_ = node["bandwidth"].as<unsigned int>();

  return true;
}
