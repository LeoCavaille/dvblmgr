#ifndef YAML_ADAPTER_HPP_
#define YAML_ADAPTER_HPP_

#include "ptr/adapter.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<AdapterPtr> {
  static Node encode(const AdapterPtr &rhs);
  static bool decode(const Node &node, AdapterPtr &c);
};
}

#endif /* YAML_ADAPTER_HPP_ */
