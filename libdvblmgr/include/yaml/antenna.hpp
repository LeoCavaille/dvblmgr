#ifndef YAML_ANTENNA_HPP_
#define YAML_ANTENNA_HPP_

#include "ptr/antenna.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<AntennaPtr> {
  static Node encode(const AntennaPtr &rhs);
  static bool decode(const Node &node, AntennaPtr &c);
};
}

#endif /* YAMLANTENNA_HPP_ */
