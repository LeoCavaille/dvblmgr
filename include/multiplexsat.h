#ifndef MULTIPLEXSAT_H_
#define MULTIPLEXSAT_H_

#include "multiplex.h"

class MultiplexSat;

namespace YAML {
template <> struct convert<MultiplexSat> {
  static Node encode(const MultiplexSat &rhs);
  static bool decode(const Node &node, MultiplexSat &rhs);
};
}

class MultiplexSat : public Multiplex {
public:
  bool isCompatible(const AdapterPtr &a) const;

  friend YAML::Node YAML::convert<MultiplexSat>::encode(const MultiplexSat &rhs);
  friend bool YAML::convert<MultiplexSat>::decode(const YAML::Node &node,
                                             MultiplexSat &rhs);

private:
  // in Hz
  unsigned int symbolRate_;

  PolarizationPtr polarizationPtr_;
  ModulationPtr modulationPtr_;
};

inline YAML::Node YAML::convert<MultiplexSat>::encode(const MultiplexSat &rhs) {
  Node node;
  // TODO-Lothar

  return node;
}

inline bool YAML::convert<MultiplexSat>::decode(const YAML::Node &node, MultiplexSat &rhs) {
  YAML::convert<Multiplex>::decode(node, rhs);
  rhs.symbolRate_ = node["symbolRate"].as<unsigned int>();

  return true;
}

#endif /* MULTIPLEXSAT_H_ */
