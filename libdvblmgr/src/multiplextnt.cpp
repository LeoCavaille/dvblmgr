#include "multiplextnt.hpp"
#include "broadcasttype.hpp"

MultiplexTnt::MultiplexTnt() {}

MultiplexTnt::MultiplexTnt(std::string name, unsigned int frequency,
                           BroadcastTypePtr broadcastTypePtr,
                           std::vector<ChannelPtr> channels,
                           unsigned int bandwidth) {
  name_ = name, frequency_ = frequency;
  broadcastTypePtr_ = broadcastTypePtr;
  channels_ = channels;
  bandwidth_ = bandwidth;
}

bool MultiplexTnt::operator==(const MultiplexTnt &rhs) const {
  return name_ == rhs.name_ && frequency_ == rhs.frequency_ &&
         *broadcastTypePtr_ == *(rhs.broadcastTypePtr_) &&
         bandwidth_ == rhs.bandwidth_;
}

bool MultiplexTnt::operator!=(const MultiplexTnt &rhs) const {
  return !(*this == rhs);
}

// TODO
bool MultiplexTnt::isCompatible(const AdapterPtr &a) const { return true; }
