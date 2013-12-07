#ifndef MULTIPLEXSAT_H_
#define MULTIPLEXSAT_H_

#include "multiplex.h"
#include "polarization_ptr.h"
#include "modulation_ptr.h"
#include "multiplexsat_yaml.h"


class MultiplexSat : public Multiplex {
public:

  bool isCompatible(const AdapterPtr &a) const;

  friend YAML::Node YAML::convert<MultiplexSat>::encode(const MultiplexPtr &rhs);
  friend bool YAML::convert<MultiplexSat>::decode(const YAML::Node &node,
                                             MultiplexPtr &rhs);

private:
  // in Hz
  unsigned int symbolRate_;
  std::string sattelite_;

  PolarizationPtr polarizationPtr_;
  ModulationPtr modulationPtr_;
};


#endif /* MULTIPLEXSAT_H_ */
