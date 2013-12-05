#ifndef BROADCASTTYPEYAML_H_
#define BROADCASTTYPEYAML_H_

class BroadcastType;

namespace YAML {
template <> struct convert<BroadcastType> {
  static Node encode(const BroadcastType &rhs);
  static bool decode(const Node &node, BroadcastType &c);
};
}

#endif /* BROADCASTTYPEYAML_H_ */