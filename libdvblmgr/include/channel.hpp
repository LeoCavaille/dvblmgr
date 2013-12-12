#ifndef CHANNEL_HPP_
#define CHANNEL_HPP_

#include "yaml/channel.hpp"
#include "confobject.hpp"

#include <vector>
#include <string>

class Channel : public ConfObject {
public:
  Channel();
  Channel(const std::string name, const unsigned int &sid,
          const std::vector<unsigned int> &pids, const bool &broadcast,
          const unsigned int &priority);

  friend YAML::Node YAML::convert<ChannelPtr>::encode(const ChannelPtr &rhs);
  friend bool YAML::convert<ChannelPtr>::decode(const YAML::Node &node,
                                                ChannelPtr &rhs);

  bool operator==(const Channel &rhs) const;
  bool operator!=(const Channel &rhs) const;

  unsigned int getPriority() { return priority_; };

private:
  // Main characteristics
  std::string name_;
  unsigned int sid_;
  std::vector<unsigned int> pids_;

  // Broadcast utils
  bool broadcast_;
  unsigned int priority_;
};

#endif /* CHANNEL_HPP_ */
