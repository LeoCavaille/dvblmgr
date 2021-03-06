#ifndef MULTIPLEXTNT_HPP_
#define MULTIPLEXTNT_HPP_

#include <string>
#include <vector>
#include "ptr/adapter.hpp"
#include "ptr/broadcasttype.hpp"
#include "ptr/channel.hpp"
#include "ptr/multiplex.hpp"
#include "multiplex.hpp"
#include "yaml/multiplextnt.hpp"

class MultiplexTnt : public Multiplex {
public:
  MultiplexTnt();
  MultiplexTnt(std::string name, unsigned int frequency,
               BroadcastTypePtr broadcastTypePtr,
               std::vector<ChannelPtr> channels, unsigned int bandwidth);

  bool isCompatible(const AdapterPtr &a) const;

  friend YAML::Node
  YAML::convert<MultiplexTntPtr>::encode(const MultiplexTntPtr &rhs);
  friend bool YAML::convert<MultiplexTntPtr>::decode(const YAML::Node &node,
                                                     MultiplexTntPtr rhs);

  bool operator==(const MultiplexTnt &rhs) const;
  bool operator!=(const MultiplexTnt &rhs) const;

private:
  // in Hz
  unsigned int bandwidth_;
};

#endif /* MULTIPLEXTNT_HPP_ */
