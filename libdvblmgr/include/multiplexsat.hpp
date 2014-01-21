#ifndef MULTIPLEXSAT_HPP_
#define MULTIPLEXSAT_HPP_

#include "multiplex.hpp"
#include "ptr/polarization.hpp"
#include "ptr/modulation.hpp"
#include "ptr/antenna.hpp"
#include "yaml/multiplexsat.hpp"


class MultiplexSat : public Multiplex {
public:
  MultiplexSat();
  MultiplexSat(std::string name,
      unsigned int frequency,
      BroadcastTypePtr broadcastTypePtr,
      std::vector<ChannelPtr> channels,
      unsigned int symbolRate,
      PolarizationPtr polarizationPtr,
      ModulationPtr modulationPtr,
      AntennaPtr antennaPtr);

  bool isCompatible(const AdapterPtr &a) const;

  friend YAML::Node YAML::convert<MultiplexSatPtr>::encode(const MultiplexSatPtr &rhs);
  friend bool YAML::convert<MultiplexSatPtr>::decode(const YAML::Node &node,
                                             MultiplexSatPtr rhs);

  AntennaPtr getAntenna() { return antennaPtr_; };

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
