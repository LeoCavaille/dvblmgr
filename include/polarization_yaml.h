#ifndef POLARIZATIONYAML_H_
#define POLARIZATIONYAML_H_

#include "polarization_ptr.h"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<PolarizationPtr> {
  static Node encode(const PolarizationPtr &rhs);
  static bool decode(const Node &node, PolarizationPtr &c);
};
}

#endif /* POLARIZATIONYAML_H_ */
