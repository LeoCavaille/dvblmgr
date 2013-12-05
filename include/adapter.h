#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "antenna_ptr.h"
#include "confobject.h"
#include "broadcasttype.h"

#include <memory>
#include <vector>

class Adapter;

namespace YAML {
template <> struct convert<Adapter> {
  static Node encode(const Adapter &rhs);
  static bool decode(const Node &node, Adapter &c);
};
}

typedef std::shared_ptr<BroadcastType> BroadcastTypePtr;

class Adapter : public ConfObject {
public:
  Adapter();
  Adapter(unsigned char id, unsigned char frontendId, const AntennaPtr& antennaPtr, const std::vector<BroadcastTypePtr>& compats);

  bool isCompatible(const BroadcastTypePtr &bt) const;

  friend YAML::Node YAML::convert<Adapter>::encode(const Adapter &rhs);
  friend bool YAML::convert<Adapter>::decode(const YAML::Node &node,
                                             Adapter &rhs);


private:
  unsigned char id_;
  unsigned char frontendId_;
  AntennaPtr antennaPtr_;
  std::vector<BroadcastTypePtr> compats_;
};

inline YAML::Node YAML::convert<Adapter>::encode(const Adapter &rhs) {
  Node node;
  node["id"] = rhs.id_;
  node["frontendId"] = rhs.frontendId_;
  for (auto& btPtr: rhs.compats_)
  {
  	node["broadcastType"].push_back(YAML::convert<BroadcastType>::encode(*btPtr));
  }

  return node;
}

inline bool YAML::convert<Adapter>::decode(const YAML::Node &node, Adapter &rhs) {
  rhs.id_ = node["id"].as<unsigned int>();
  rhs.frontendId_ = node["frontendId"].as<unsigned int>();
  rhs.antennaPtr_ = std::make_shared(std::move(node["antenna"].as<Antenna>()));
  for (const_iterator it = node["broadcastType"].begin(); it != node["broadcastType"].end();
      ++it) {
    rhs.compats_.push_back(std::make_shared(std::move(it->as<BroadcastType>())));
  }

  return true;
}

#endif /* ADAPTER_H_ */
