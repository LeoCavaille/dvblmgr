#ifndef MULTIPLEXSAT_H_
#define MULTIPLEXSAT_H_

#include "multiplex.h"
#include "polarization_ptr.h"
#include "modulation_ptr.h"
#include "multiplexsat_yaml.h"


class MultiplexSat : public Multiplex {
public:
  bool isCompatible(const AdapterPtr &a) const;

  friend YAML::Node YAML::convert<MultiplexSatPtr>::encode(const MultiplexSatPtr &rhs);
  friend bool YAML::convert<MultiplexSatPtr>::decode(const YAML::Node &node,
                                             MultiplexSatPtr rhs);

private:
  // in Hz
  unsigned int symbolRate_;
  std::string satellite_;

  PolarizationPtr polarizationPtr_;
  ModulationPtr modulationPtr_;
};


#endif /* MULTIPLEXSAT_H_ */
