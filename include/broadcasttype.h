#ifndef BROADCASTTYPE_H_
#define BROADCASTTYPE_H_

#include "confobject.h"
#include "broadcasttype_yaml.h"

#include <string>



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

  friend YAML::Node
      YAML::convert<BroadcastType>::encode(const BroadcastType &rhs);
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

inline YAML::Node
YAML::convert<BroadcastType>::encode(const BroadcastType &rhs) {
  Node node;
  node = rhs.typeString_;
  return node;
}

inline bool YAML::convert<BroadcastType>::decode(const YAML::Node &node,
                                                 BroadcastType &rhs) {
  rhs.type_ = BroadcastType::FromString(node.Scalar());
  rhs.typeString_ = BroadcastType::ToString(rhs.type_);
  return (rhs.type_ != BroadcastType::invalid);
}

#endif /* BROADCASTTYPE_H_ */
