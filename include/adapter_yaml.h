#ifndef ADAPTERYAML_H_
#define ADAPTERYAML_H_

#include "adapter_ptr.h"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<AdapterPtr> {
  static Node encode(const AdapterPtr &rhs);
  static bool decode(const Node &node, AdapterPtr &c);
};
}

#endif /* ADAPTERYAML_H_ */