#ifndef YAML_MODULATION_HPP_
#define YAML_MODULATION_HPP_

#include "ptr/modulation.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<ModulationPtr> {
  static Node encode(const ModulationPtr &rhs);
  static bool decode(const Node &node, ModulationPtr &c);
};
}

#endif /* YAML_MODULATION_HPP_ */