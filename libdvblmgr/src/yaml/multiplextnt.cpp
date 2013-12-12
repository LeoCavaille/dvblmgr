#include "multiplextnt.hpp"
#include "yaml/multiplextnt.hpp"

YAML::Node YAML::convert<MultiplexTntPtr>::encode(const MultiplexTntPtr &rhs) {
  Node node = YAML::convert<MultiplexPtr>::encode(rhs);
  node["type"] = "TNT";
  node["bandwidth"] = rhs->bandwidth_;
  return node;
}

bool YAML::convert<MultiplexTntPtr>::decode(const YAML::Node &node, MultiplexTntPtr rhs) {
  YAML::convert<MultiplexPtr>::decode(node, rhs);

  // Then TNT specific parsing
  rhs->bandwidth_ = node["bandwidth"].as<unsigned int>();

  return true;
}
