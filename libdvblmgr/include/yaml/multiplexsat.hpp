#ifndef YAML_MULTIPLEXSAT_HPP_
#define YAML_MULTIPLEXSAT_HPP_

#include "ptr/multiplexsat.hpp"
#include <yaml-cpp/yaml.h>

class MultiplexSat;

namespace YAML {
template <> struct convert<MultiplexSatPtr> {
  static Node encode(const MultiplexSatPtr &rhs);
  static bool decode(const Node &node, MultiplexSatPtr c);
};
}

#endif /* YAML_MULTIPLEXSAT_HPP_ */
