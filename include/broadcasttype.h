#ifndef BROADCASTTYPE_H_
#define BROADCASTTYPE_H_

#include "confobject.h"

#include <string>

class BroadcastType;

namespace YAML {
template <> struct convert<BroadcastType> {
  static Node encode(const BroadcastType &rhs);
  static bool decode(const Node &node, BroadcastType &c);
};
}

class BroadcastType : public ConfObject {
public:
  enum Enum {
  	none,
    dvbs,
    dvbstwo,
    dvbt,
    invalid
  };

  BroadcastType();
  BroadcastType(Enum m);
  explicit BroadcastType(const std::string &m);

  friend YAML::Node YAML::convert<BroadcastType>::encode(const BroadcastType &rhs);
  friend bool YAML::convert<BroadcastType>::decode(const YAML::Node &node,
                                             BroadcastType &rhs);

  bool operator==(const std::string &ss) const;
  bool operator==(const BroadcastType &rhs) const;

  static Enum FromString(std::string mString);
  static std::string ToString(const Enum &m);

private:
  Enum type_;
  std::string typeString_;
};


inline YAML::Node YAML::convert<BroadcastType>::encode(const BroadcastType &rhs) {
  Node node;

  return node;
}

inline bool YAML::convert<BroadcastType>::decode(const YAML::Node &node, BroadcastType &rhs) {

  return true;
}


#endif /* BROADCASTTYPE_H_ */
