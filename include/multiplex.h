#ifndef MULTIPLEX_H_
#define MULTIPLEX_H_

#include "adapterptr.h"
#include "antennaptr.h"
#include "antenna.h"
#include "broadcasttypeptr.h"
#include "broadcasttype.h"
#include "channelptr.h"
#include "modulationptr.h"
#include "polarizationptr.h"

#include "confobject.h"

#include <string>
#include <vector>

class Multiplex;
namespace YAML {
template <> struct convert<Multiplex> {
  static Node encode(const Multiplex &rhs);
  static bool decode(const Node &node, Multiplex &rhs);
};
}

class Multiplex : public ConfObject {
public:
  virtual bool isCompatible(const AdapterPtr &a) const = 0;

  friend YAML::Node YAML::convert<Multiplex>::encode(const Multiplex &rhs);
  friend bool YAML::convert<Multiplex>::decode(const YAML::Node &node,
                                             Multiplex &rhs);

private:
  std::string name_;

  // in Hz
  unsigned int frequency_;
  unsigned int priority_;

  AntennaPtr antennaPtr_;
  BroadcastTypePtr broadcastTypePtr_;

  std::vector<ChannelPtr> channels_;
};

inline YAML::Node YAML::convert<Multiplex>::encode(const Multiplex &rhs) {
  Node node;
  // TODO-Lothar
  node["name"] = rhs.name_;

  return node;
}

inline bool YAML::convert<Multiplex>::decode(const YAML::Node &node, Multiplex &rhs) {
  rhs.name_ = node["name"].as<std::string>();
  rhs.frequency_ = node["frequency"].as<unsigned int>();
  rhs.priority_ = node["priority"].as<unsigned int>();

  rhs.antennaPtr_ = std::make_shared<Antenna>(std::move(node["antenna"].as<Antenna>()));
  rhs.broadcastTypePtr_ = std::make_shared<BroadcastType>(std::move(node["broadcastType"].as<BroadcastType>()));

  return true;
}

#endif /* MULTIPLEX_H_ */
