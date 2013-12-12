#ifndef MODULATION_HPP_
#define MODULATION_HPP_

#include "yaml/modulation.hpp"
#include "confobject.hpp"

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

  bool operator==(const Enum &e) const;
  bool operator==(const Modulation &mPtr) const;
  static Enum FromString(std::string mString);
  static std::string ToString(const Enum &m);

  friend YAML::Node YAML::convert<ModulationPtr>::encode(const ModulationPtr &rhs);
  friend bool YAML::convert<ModulationPtr>::decode(const YAML::Node &node,
                                             ModulationPtr &rhs);

private:
  Enum type_;
  std::string typeString_;
};

#endif /* MODULATION_HPP_ */
