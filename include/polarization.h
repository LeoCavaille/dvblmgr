#ifndef POLARIZATION_H_
#define POLARIZATION_H_

#include "confobject.h"
#include "polarization_yaml.h"

#include <string>



class Polarization : public ConfObject {
public:
  enum Enum {
    none,
    vertical,
    horizontal,
    invalid
  };

  Polarization();
  Polarization(Enum m);
  explicit Polarization(const std::string &p);

  friend YAML::Node
      YAML::convert<PolarizationPtr>::encode(const PolarizationPtr &rhs);
  friend bool YAML::convert<PolarizationPtr>::decode(const YAML::Node &node,
                                                   PolarizationPtr &rhs);

  bool operator==(const std::string &ss) const;
  bool operator==(const Enum &rhs) const;
  bool operator==(const Polarization &rhs) const;

  static Enum FromString(std::string pString);
  static std::string ToString(const Enum &p);

private:
  Enum polarization_;
  std::string pString_;
};

#endif /* POLARIZATION_H_ */
