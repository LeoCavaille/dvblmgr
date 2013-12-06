#ifndef MODULATION_H_
#define MODULATION_H_

#include "modulation_yaml.h"
#include "confobject.h"

#include <string>

class Modulation : public ConfObject {
public:
  enum Enum {
    none,
    qpsk,
    eightpsk,
    invalid
  };

  Modulation();
  Modulation(Enum m);
  explicit Modulation(const std::string &m);

  bool operator==(const std::string &ss) const;
  static Enum FromString(std::string mString);
  static std::string ToString(const Enum &m);

  friend YAML::Node YAML::convert<ModulationPtr>::encode(const ModulationPtr &rhs);
  friend bool YAML::convert<ModulationPtr>::decode(const YAML::Node &node,
                                             ModulationPtr &rhs);

private:
  Enum type_;
  std::string typeString_;
};

#endif /* MODULATION_H_ */
