#ifndef YAML_MULTIPLEX_HPP_
#define YAML_MULTIPLEX_HPP_

#include "ptr/multiplex.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<MultiplexPtr> {
  static Node encode(const MultiplexPtr &rhs);
  static bool decode(const Node &node, MultiplexPtr c);
};
}

#endif /* YAML_MULTIPLEX_HPP_ */
