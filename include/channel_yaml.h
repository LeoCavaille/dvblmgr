#ifndef CHANNELYAML_H_
#define CHANNELYAML_H_

#include "channel_ptr.h"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<ChannelPtr> {
  static Node encode(const ChannelPtr &rhs);
  static bool decode(const Node &node, ChannelPtr &c);
};
}

#endif /* CHANNELYAML_H_ */