#ifndef MACHINEYAML_H_
#define MACHINEYAML_H_

#include "machine_ptr.h"
#include <yaml-cpp/yaml.h>


class Machine;

namespace YAML {
template <> struct convert<MachinePtr> {
  static Node encode(const MachinePtr &rhs);
  static bool decode(const Node &node, MachinePtr &rhs);
};
}

#endif /* MACHINEYAML_H_ */
