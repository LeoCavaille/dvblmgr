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
      YAML::convert<BroadcastTypePtr>::encode(const BroadcastTypePtr &rhs);
  friend bool YAML::convert<BroadcastTypePtr>::decode(const YAML::Node &node,
                                                      BroadcastTypePtr &rhs);

  bool operator==(const std::string &ss) const;
  bool operator==(const Enum &rhs) const;
  bool operator==(const BroadcastTypePtr &rhs) const;

  static Enum FromString(std::string mString);
  static std::string ToString(const Enum &m);

private:
  Enum type_;
  std::string typeString_;
};

#endif /* BROADCASTTYPE_H_ */
