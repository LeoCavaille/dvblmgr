#ifndef SERVERYAML_H_
#define SERVERYAML_H_

#include "server_ptr.h"
#include <yaml-cpp/yaml.h>


class Server;

namespace YAML {
template <> struct convert<ServerPtr> {
  static Node encode(const ServerPtr &rhs);
  static bool decode(const Node &node, ServerPtr &rhs);
};
}

#endif /* SERVERYAML_H_ */
