#ifndef YAML_BROADCASTTYPE_HPP_
#define YAML_BROADCASTTYPE_HPP_

#include "ptr/broadcasttype.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<BroadcastTypePtr> {
  static Node encode(const BroadcastTypePtr &rhs);
  static bool decode(const Node &node, BroadcastTypePtr &c);
};
}

#endif /* YA_MLBROADCASTTYPE_HPP_ */
