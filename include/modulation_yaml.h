#ifndef MODULATIONYAML_H_
#define MODULATIONYAML_H_

#include "modulation_ptr.h"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<ModulationPtr> {
  static Node encode(const ModulationPtr &rhs);
  static bool decode(const Node &node, ModulationPtr &c);
};
}

#endif /* MODULATIONYAML_H_ */