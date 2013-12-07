#include "multiplexsat.h"
#include "multiplexsat_yaml.h"
#include "polarization_yaml.h"

YAML::Node YAML::convert<MultiplexSat>::encode(const MultiplexPtr &rhs) {
  Node node;
  return node;
}

bool YAML::convert<MultiplexSat>::decode(const YAML::Node &node, MultiplexPtr &rhs) {
  YAML::convert<MultiplexPtr>::decode(node, rhs);

  // Then SAT specific parsing
  rhs->symbolRate_ = node["symbolrate"].as<unsigned int>();
  rhs->satellite_ = node["satellite"].as<std::string>();
  rhs->polarizationPtr_ = node["polarization"].as<PolarizationPtr>();
  rhs->modulationPtr_ = node["modulation"].as<ModulationPtr>();

  return true;
}