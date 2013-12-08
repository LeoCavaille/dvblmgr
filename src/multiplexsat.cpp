#include "multiplexsat.h"

MultiplexSat::MultiplexSat() {};

MultiplexSat::MultiplexSat(std::string name,
    unsigned int frequency,
    BroadcastTypePtr broadcastTypePtr,
    std::vector<ChannelPtr> channels,
    unsigned int symbolRate,
    std::string satellite,
    PolarizationPtr polarizationPtr,
    ModulationPtr modulationPtr) {
  name_ = name,
  frequency_ = frequency;
  broadcastTypePtr_ = broadcastTypePtr;
  channels_ = channels;
  symbolRate_ = symbolRate;
  satellite_ = satellite;
  polarizationPtr_ = polarizationPtr;
  modulationPtr_ = modulationPtr;
}

bool MultiplexSat::operator==(const MultiplexSat &rhs) const {
  return name_ == rhs.name_ &&
      frequency_ == rhs.frequency_ &&
      // *broadcastTypePtr_ == rhs.broadcastTypePtr_ &&
      symbolRate_ == rhs.symbolRate_ &&
      satellite_ == rhs.satellite_ &&
      // *polarizationPtr_ == rhs.polarizationPtr_ &&
      // *modulationPtr_ == rhs.modulationPtr_;
      true;
}

bool MultiplexSat::operator!=(const MultiplexSat &rhs) const {
  return !(*this==rhs);
}


// TODO
bool MultiplexSat::isCompatible(const AdapterPtr &a) const {
    return true;
}