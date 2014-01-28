#ifndef MULTIPLEX_HPP_
#define MULTIPLEX_HPP_

#include "ptr/adapter.hpp"
#include "ptr/antenna.hpp"
#include "ptr/broadcasttype.hpp"
#include "ptr/channel.hpp"

#include "yaml/multiplex.hpp"

#include <string>
#include <vector>

class Multiplex {
public:
  virtual bool isCompatible(const AdapterPtr &a) const = 0;

  friend YAML::Node
  YAML::convert<MultiplexPtr>::encode(const MultiplexPtr &rhs);
  friend bool YAML::convert<MultiplexPtr>::decode(const YAML::Node &node,
                                                  MultiplexPtr rhs);

  static std::string getType(const YAML::Node &node);

  BroadcastTypePtr getBroadcastType() {
    return broadcastTypePtr_;
  };

  unsigned int getPriority() { return priority_; }
  void updatePriority();

protected:
  std::string name_;
  unsigned int priority_;

  unsigned int frequency_;

  BroadcastTypePtr broadcastTypePtr_;

  std::vector<ChannelPtr> channels_;
};

#endif /* MULTIPLEX_HPP_ */
