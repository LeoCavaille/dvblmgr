#ifndef YAML_MULTIPLEXTNT_HPP_
#define YAML_MULTIPLEXTNT_HPP_

#include "ptr/multiplextnt.hpp"
#include <yaml-cpp/yaml.h>


class MultiplexTnt;

namespace YAML {
template <> struct convert<MultiplexTntPtr> {
  static Node encode(const MultiplexTntPtr &rhs);
  static bool decode(const Node &node, MultiplexTntPtr c);
};
}

#endif /* YAML_MULTIPLEXTNT_HPP_ */
