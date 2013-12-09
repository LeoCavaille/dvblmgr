#ifndef ANTENNA_H_
#define ANTENNA_H_

#include "confobject.h"
#include "antenna_yaml.h"

#include <string>

class Antenna : public ConfObject {
public:
  Antenna();
  Antenna(const std::string &name);

  friend YAML::Node YAML::convert<AntennaPtr>::encode(const AntennaPtr &rhs);
  friend bool YAML::convert<AntennaPtr>::decode(const YAML::Node &node,
                                                AntennaPtr &rhs);

  std::string getName() const { return name_; }

  bool operator==(const Antenna &rhs) const;
  bool operator!=(const Antenna &rhs) const;

private:
  std::string name_;
};

#endif /* ANTENNA_H_ */
