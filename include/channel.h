#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "channel_yaml.h"
#include "confobject.h"

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

private:
  // Main characteristics
  std::string name_;
  unsigned int sid_;
  std::vector<unsigned int> pids_;

  // Broadcast utils
  bool broadcast_;
  unsigned int priority_;
};

#endif /* CHANNEL_H_ */
