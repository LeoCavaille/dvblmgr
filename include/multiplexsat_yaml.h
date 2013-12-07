#ifndef MULTIPLEXSATYAML_H_
#define MULTIPLEXSATYAML_H_

#include "multiplex_ptr.h"
#include <yaml-cpp/yaml.h>

class MultiplexSat;

namespace YAML {
template <> struct convert<MultiplexSat> {
  static Node encode(const MultiplexPtr &rhs);
  static bool decode(const Node &node, MultiplexPtr &c);
};
}

#endif /* MULTIPLEXSATYAML_H_ */