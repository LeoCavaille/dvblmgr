#ifndef MULTIPLEXYAML_H_
#define MULTIPLEXYAML_H_

#include "multiplex_ptr.h"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<MultiplexPtr> {
  static Node encode(const MultiplexPtr &rhs);
  static bool decode(const Node &node, MultiplexPtr &c);
};
}

#endif /* MULTIPLEXYAML_H_ */