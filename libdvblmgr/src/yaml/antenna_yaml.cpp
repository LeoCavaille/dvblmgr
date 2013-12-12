#include "yaml/antenna.h"
#include "antenna.h"

YAML::Node YAML::convert<AntennaPtr>::encode(const AntennaPtr &rhs) {
  Node node;
  node = rhs->name_;

  return node;
}

bool YAML::convert<AntennaPtr>::decode(const YAML::Node &node, AntennaPtr &rhs) {
  rhs->name_ = node.Scalar();

  return true;
}