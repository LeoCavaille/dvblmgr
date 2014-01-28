#ifndef YAML_MACHINE_HPP_
#define YAML_MACHINE_HPP_

#include "ptr/machine.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<MachinePtr> {
  static Node encode(const MachinePtr &rhs);
  static bool decode(const Node &node, MachinePtr &rhs);
};
}

#endif /* YAML_MACHINE_HPP_ */
