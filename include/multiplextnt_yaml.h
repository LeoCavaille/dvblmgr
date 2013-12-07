#ifndef MULTIPLEXTNTYAML_H_
#define MULTIPLEXTNTYAML_H_

#include "multiplex_ptr.h"
#include <yaml-cpp/yaml.h>


class MultiplexTnt;

namespace YAML {
template <> struct convert<MultiplexTnt> {
  static Node encode(const MultiplexPtr &rhs);
  static bool decode(const Node &node, MultiplexPtr &c);
};
}

#endif /* MULTIPLEXTNTYAML_H_ */