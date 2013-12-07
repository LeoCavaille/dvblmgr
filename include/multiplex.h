#ifndef MULTIPLEX_H_
#define MULTIPLEX_H_

#include "adapter_ptr.h"
#include "antenna_ptr.h"
#include "broadcasttype_ptr.h"
#include "channel_ptr.h"

#include "multiplex_yaml.h"
#include "confobject.h"

#include <string>
#include <vector>


class Multiplex : public ConfObject {
public:
  virtual bool isCompatible(const AdapterPtr &a) const = 0;

  friend YAML::Node YAML::convert<MultiplexPtr>::encode(const MultiplexPtr &rhs);
  friend bool YAML::convert<MultiplexPtr>::decode(const YAML::Node &node,
                                             MultiplexPtr &rhs);

private:
  std::string name_;

  unsigned int frequency_;

  // DVB-S only
  // AntennaPtr antennaPtr_;
  BroadcastTypePtr broadcastTypePtr_;

  std::vector<ChannelPtr> channels_;
};

#endif /* MULTIPLEX_H_ */
