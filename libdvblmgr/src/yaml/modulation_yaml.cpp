#include "yaml/modulation.h"
#include "modulation.h"

YAML::Node YAML::convert<ModulationPtr>::encode(const ModulationPtr &rhs) {
  Node node;
  node = rhs->typeString_;
  return node;
}

bool YAML::convert<ModulationPtr>::decode(const YAML::Node &node,
                                                 ModulationPtr &rhs) {
  rhs->type_ = Modulation::FromString(node.Scalar());
  rhs->typeString_ = Modulation::ToString(rhs->type_);
  return (rhs->type_ != Modulation::invalid);
}
