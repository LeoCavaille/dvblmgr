#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "confobject.h"

#include <vector>
#include <string>

class Channel;

namespace YAML {
template <> struct convert<Channel> {
  static Node encode(const Channel &rhs);
  static bool decode(const Node &node, Channel &c);
};
}

class Channel : public ConfObject {
public:
  Channel();
  Channel(const std::string name, const unsigned int &sid,
          const std::vector<unsigned int> &pids);

  friend YAML::Node YAML::convert<Channel>::encode(const Channel &rhs);
  friend bool YAML::convert<Channel>::decode(const YAML::Node &node,
                                             Channel &rhs);

  bool operator==(const Channel &rhs) const;
  bool operator!=(const Channel &rhs) const;

private:
  // Main characteristics
  std::string name_;
  unsigned int sid_;
  std::vector<unsigned int> pids_;

  // Broadcast utils
  bool broadcast_;

};

inline YAML::Node YAML::convert<Channel>::encode(const Channel &rhs) {
  Node node;
  node["name"] = rhs.name_;
  node["sid"] = rhs.sid_;
  for(auto& pid: rhs.pids_) {
    node["pids"].push_back(pid);
  }

  return node;
}

inline bool YAML::convert<Channel>::decode(const YAML::Node &node, Channel &rhs) {
  rhs.name_ = node["name"].as<std::string>();
  rhs.sid_ = node["sid"].as<unsigned int>();
  for (const_iterator it = node["pids"].begin(); it != node["pids"].end();
      ++it) {
    rhs.pids_.push_back(it->as<unsigned int>());
  }
  return true;
}

#endif /* CHANNEL_H_ */
