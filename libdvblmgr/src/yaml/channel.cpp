#include "yaml/channel.hpp"
#include "channel.hpp"

YAML::Node YAML::convert<ChannelPtr>::encode(const ChannelPtr &rhs) {
  Node node;
  node["name"] = rhs->name_;
  node["sid"] = rhs->sid_;
  for(auto& pid: rhs->pids_) {
    node["pids"].push_back(pid);
  }
  node["broadcast"] = rhs->broadcast_;
  node["priority"] = rhs->priority_;

  return node;
}

bool YAML::convert<ChannelPtr>::decode(const YAML::Node &node, ChannelPtr &rhs) {
  rhs->name_ = node["name"].as<std::string>();
  rhs->sid_ = node["sid"].as<unsigned int>();
  for (auto it = node["pids"].begin(); it != node["pids"].end();
      ++it) {
    rhs->pids_.push_back(it->as<unsigned int>());
  }
  if (node["broadcast"]){
    rhs->broadcast_ = node["broadcast"].as<bool>();
  }
  rhs->priority_ = node["priority"].as<unsigned int>();

  return true;
}
