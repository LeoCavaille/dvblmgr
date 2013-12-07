#ifndef MULTIPLEXSATYAML_H_
#define MULTIPLEXSATYAML_H_

#include "multiplexsat_ptr.h"
#include <yaml-cpp/yaml.h>

class MultiplexSat;

namespace YAML {
template <> struct convert<MultiplexSatPtr> {
  static Node encode(const MultiplexSatPtr &rhs);
  static bool decode(const Node &node, MultiplexSatPtr c);
};
}

#endif /* MULTIPLEXSATYAML_H_ */
