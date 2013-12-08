
// We need the MultiplexSat definition because we fill in the class members
#include "multiplexsat.h"
// We need also these definitions because we create objects (later referenced
// by Ptr) inside MultiplexSat structure
#include "modulation.h"
#include "polarization.h"

// Include the definition of these YAML functions (however useless because already
// included with multiplexsat.h)
#include "multiplexsat_yaml.h"
// We need the parent class YAML convert functions as well to fill in the base class
// member
#include "multiplex_yaml.h"


YAML::Node YAML::convert<MultiplexSatPtr>::encode(const MultiplexSatPtr &rhs) {
  Node node = YAML::convert<MultiplexPtr>::encode(rhs);
  node["type"] = "SAT";
  node["symbolRate"] = rhs->symbolRate_;
  node["polarization"] = YAML::convert<PolarizationPtr>::encode(rhs->polarizationPtr_);
  node["modulation"] = YAML::convert<ModulationPtr>::encode(rhs->modulationPtr_);
  return node;
}

bool YAML::convert<MultiplexSatPtr>::decode(const YAML::Node &node, MultiplexSatPtr rhs) {

  // Call decode within the base class, for type compability we need dynamic casting
  YAML::convert<MultiplexPtr>::decode(node, std::dynamic_pointer_cast<Multiplex>(rhs));

  // Then SAT specific parsing
  rhs->symbolRate_ = node["symbolrate"].as<unsigned int>();
  rhs->satellite_ = node["satellite"].as<std::string>();
  rhs->polarizationPtr_ = std::make_shared<Polarization>();
  YAML::convert<PolarizationPtr>::decode(node["polarization"], rhs->polarizationPtr_);
  rhs->modulationPtr_ = std::make_shared<Modulation>();
  YAML::convert<ModulationPtr>::decode(node["modulation"], rhs->modulationPtr_);
  return true;
}
