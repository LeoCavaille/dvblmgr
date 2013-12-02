#ifndef BROADCASTTYPE_H_
#define BROADCASTTYPE_H_

#include "confobject.h"

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

  bool operator==(const std::string &ss) const;
  bool operator==(const BroadcastType &rhs) const;

  static Enum FromString(std::string mString);
  static std::string ToString(const Enum &m);

private:
  Enum type_;
  std::string typeString_;
};

#endif /* BROADCASTTYPE_H_ */
