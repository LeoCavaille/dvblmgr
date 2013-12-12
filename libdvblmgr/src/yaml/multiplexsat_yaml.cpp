
// We need the MultiplexSat definition because we fill in the class members
#include "multiplexsat.h"
// We need also these definitions because we create objects (later referenced
// by Ptr) inside MultiplexSat structure
#include "modulation.h"
#include "polarization.h"
#include "antenna.h"

// Include the definition of these YAML functions (however useless because already
// included with multiplexsat.h)
#include "yaml/multiplexsat.h"
// We need the parent class YAML convert functions as well to fill in the base class
// member
#include "yaml/multiplex.h"


YAML::Node YAML::convert<MultiplexSatPtr>::encode(const MultiplexSatPtr &rhs) {
  Node node = YAML::convert<MultiplexPtr>::encode(rhs);
  node["type"] = "SAT";
  node["symbolRate"] = rhs->symbolRate_;
  node["polarization"] = YAML::convert<PolarizationPtr>::encode(rhs->polarizationPtr_);
  node["modulation"] = YAML::convert<ModulationPtr>::encode(rhs->modulationPtr_);
  node["antenna"] = YAML::convert<AntennaPtr>::encode(rhs->antennaPtr_);
  return node;
}

bool YAML::convert<MultiplexSatPtr>::decode(const YAML::Node &node, MultiplexSatPtr rhs) {

  // Call decode within the base class, for type compability we need dynamic casting
  YAML::convert<MultiplexPtr>::decode(node, rhs);

  // Then SAT specific parsing
  rhs->symbolRate_ = node["symbolRate"].as<unsigned int>();
  rhs->polarizationPtr_ = std::make_shared<Polarization>();
  YAML::convert<PolarizationPtr>::decode(node["polarization"], rhs->polarizationPtr_);
  rhs->modulationPtr_ = std::make_shared<Modulation>();
  YAML::convert<ModulationPtr>::decode(node["modulation"], rhs->modulationPtr_);
  rhs->antennaPtr_ = std::make_shared<Antenna>();
  YAML::convert<AntennaPtr>::decode(node["antenna"], rhs->antennaPtr_);
  return true;
}
