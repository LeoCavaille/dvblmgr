#ifndef YAML_POLARIZATION_HPP_
#define YAML_POLARIZATION_HPP_

#include "ptr/polarization.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<PolarizationPtr> {
  static Node encode(const PolarizationPtr &rhs);
  static bool decode(const Node &node, PolarizationPtr &c);
};
}

#endif /* YA_MLPOLARIZATION_HPP_ */
