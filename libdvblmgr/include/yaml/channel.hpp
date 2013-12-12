#ifndef YAML_CHANNEL_HPP_
#define YAML_CHANNEL_HPP_

#include "ptr/channel.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<ChannelPtr> {
  static Node encode(const ChannelPtr &rhs);
  static bool decode(const Node &node, ChannelPtr &c);
};
}

#endif /* YAML_CHANNEL_HPP_ */