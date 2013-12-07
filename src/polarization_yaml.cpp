#include "polarization_yaml.h"
#include "polarization.h"

YAML::Node YAML::convert<PolarizationPtr>::encode(const PolarizationPtr &rhs) {
  Node node;
  node = rhs->pString_;
  return node;
}

bool YAML::convert<PolarizationPtr>::decode(const YAML::Node &node,
                                                 PolarizationPtr &rhs) {
  rhs->polarization_ = Polarization::FromString(node.Scalar());
  rhs->pString_ = Polarization::ToString(rhs->polarization_);
  return (rhs->polarization_ != Polarization::invalid);
}
