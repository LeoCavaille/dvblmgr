#ifndef ANTENNAYAML_H_
#define ANTENNAYAML_H_

#include "antenna_ptr.h"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<AntennaPtr> {
  static Node encode(const AntennaPtr &rhs);
  static bool decode(const Node &node, AntennaPtr &c);
};
}

#endif /* ANTENNAYAML_H_ */