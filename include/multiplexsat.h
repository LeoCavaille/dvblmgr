#ifndef MULTIPLEXSAT_H_
#define MULTIPLEXSAT_H_

#include "multiplex.h"
#include "polarization_ptr.h"
#include "modulation_ptr.h"
#include "antenna_ptr.h"
#include "multiplexsat_yaml.h"


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

  bool operator==(const MultiplexSat &rhs) const;
  bool operator!=(const MultiplexSat &rhs) const;
private:
  // in Hz
  unsigned int symbolRate_;

  PolarizationPtr polarizationPtr_;
  ModulationPtr modulationPtr_;
  AntennaPtr antennaPtr_;
};


#endif /* MULTIPLEXSAT_H_ */
