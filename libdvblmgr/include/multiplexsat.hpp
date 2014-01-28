#ifndef MULTIPLEXSAT_HPP_
#define MULTIPLEXSAT_HPP_

#include <string>                       // for string
#include <vector>                       // for vector
#include "multiplex.hpp"                // for Multiplex
#include "ptr/adapter.hpp"              // for AdapterPtr
#include "ptr/antenna.hpp"              // for AntennaPtr
#include "ptr/broadcasttype.hpp"        // for BroadcastTypePtr
#include "ptr/channel.hpp"              // for ChannelPtr
#include "ptr/modulation.hpp"           // for ModulationPtr
#include "ptr/multiplexsat.hpp"         // for MultiplexSatPtr
#include "ptr/polarization.hpp"         // for PolarizationPtr
#include "yaml/multiplexsat.hpp"        // for convert


class MultiplexSat : public Multiplex {
public:
  MultiplexSat();
  MultiplexSat(std::string name, unsigned int frequency,
               BroadcastTypePtr broadcastTypePtr,
               std::vector<ChannelPtr> channels, unsigned int symbolRate,
               PolarizationPtr polarizationPtr, ModulationPtr modulationPtr,
               AntennaPtr antennaPtr);

  bool isCompatible(const AdapterPtr &a) const;

  friend YAML::Node
  YAML::convert<MultiplexSatPtr>::encode(const MultiplexSatPtr &rhs);
  friend bool YAML::convert<MultiplexSatPtr>::decode(const YAML::Node &node,
                                                     MultiplexSatPtr rhs);

  AntennaPtr getAntenna() {
    return antennaPtr_;
  };

  bool operator==(const MultiplexSat &rhs) const;
  bool operator!=(const MultiplexSat &rhs) const;

private:
  // in Hz
  unsigned int symbolRate_;

  PolarizationPtr polarizationPtr_;
  ModulationPtr modulationPtr_;
  AntennaPtr antennaPtr_;
};

#endif /* MULTIPLEXSAT_HPP_ */
