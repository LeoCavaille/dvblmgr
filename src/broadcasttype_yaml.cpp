#include "broadcasttype_yaml.h"
#include "broadcasttype.h"

YAML::Node YAML::convert<BroadcastTypePtr>::encode(const BroadcastTypePtr &rhs) {
  Node node;
  node = rhs->typeString_;
  return node;
}

bool YAML::convert<BroadcastTypePtr>::decode(const YAML::Node &node,
                                                 BroadcastTypePtr &rhs) {
  rhs->type_ = BroadcastType::FromString(node.Scalar());
  rhs->typeString_ = BroadcastType::ToString(rhs->type_);
  return (rhs->type_ != BroadcastType::invalid);
}
