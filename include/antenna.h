#ifndef ANTENNA_H_
#define ANTENNA_H_

#include "confobject.h"

#include <string>

class Antenna;

namespace YAML {
template <> struct convert<Antenna> {
  static Node encode(const Antenna &rhs);
  static bool decode(const Node &node, Antenna &c);
};
}

class Antenna : public ConfObject {
public:
  Antenna();
  Antenna(const std::string &name) : name_(name) {}

  friend YAML::Node YAML::convert<Antenna>::encode(const Antenna &rhs);
  friend bool YAML::convert<Antenna>::decode(const YAML::Node &node,
                                             Antenna &rhs);

  std::string getName() const { return name_; }

  bool operator==(const Antenna &rhs) const { return name_ == rhs.name_; }
  bool operator!=(const Antenna &rhs) const { return !(*this == rhs); }

private:
  std::string name_;
};


inline YAML::Node YAML::convert<Antenna>::encode(const Antenna &rhs) {
  Node node;
  node["name"] = rhs.name_;

  return node;
}

inline bool YAML::convert<Antenna>::decode(const YAML::Node &node, Antenna &rhs) {
  rhs.name_ = node["name"].as<std::string>();

  return true;
}

#endif /* ANTENNA_H_ */
