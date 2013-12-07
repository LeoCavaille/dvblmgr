#ifndef BROADCASTTYPEYAML_H_
#define BROADCASTTYPEYAML_H_

#include "broadcasttype_ptr.h"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<BroadcastTypePtr> {
  static Node encode(const BroadcastTypePtr &rhs);
  static bool decode(const Node &node, BroadcastTypePtr &c);
};
}

#endif /* BROADCASTTYPEYAML_H_ */