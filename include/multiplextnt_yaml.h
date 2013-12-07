#ifndef MULTIPLEXTNTYAML_H_
#define MULTIPLEXTNTYAML_H_

#include "multiplextnt_ptr.h"
#include <yaml-cpp/yaml.h>


class MultiplexTnt;

namespace YAML {
template <> struct convert<MultiplexTntPtr> {
  static Node encode(const MultiplexTntPtr &rhs);
  static bool decode(const Node &node, MultiplexTntPtr &c);
};
}

#endif /* MULTIPLEXTNTYAML_H_ */
