#include "channel_yaml.h"
#include "channel.h"

YAML::Node YAML::convert<ChannelPtr>::encode(const ChannelPtr &rhs) {
  Node node;
  node["name"] = rhs->name_;
  node["sid"] = rhs->sid_;
  for(auto& pid: rhs->pids_) {
    node["pids"].push_back(pid);
  }

  return node;
}

bool YAML::convert<ChannelPtr>::decode(const YAML::Node &node, ChannelPtr &rhs) {
  rhs->name_ = node["name"].as<std::string>();
  rhs->sid_ = node["sid"].as<unsigned int>();
  for (auto it = node["pids"].begin(); it != node["pids"].end();
      ++it) {
    rhs->pids_.push_back(it->as<unsigned int>());
  }
  return true;
}