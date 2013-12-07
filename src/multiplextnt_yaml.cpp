#include "multiplextnt.h"
#include "multiplextnt_yaml.h"

YAML::Node YAML::convert<MultiplexTnt>::encode(const MultiplexPtr &rhs) {
  Node node;
  return node;
}

bool YAML::convert<MultiplexTnt>::decode(const YAML::Node &node, MultiplexPtr &rhs) {
  MultiplexPtr m = std::make_shared<MultiplexTnt>();
  YAML::convert<MultiplexPtr>::decode(node, m);

  // TODO
  // Then TNT specific parsing

  // rhs->name_ = node["name"].as<std::string>();
  // rhs->frequency_ = node["frequency"].as<unsigned int>();

  // rhs->broadcastTypePtr_ = node["broadcastType"].as<BroadcastTypePtr>();

  // for(unsigned i=0; i<node["channels"].size(); i++) {
  //   rhs->channels_.push_back(node["channels"][i].as<ChannelPtr>());
  // }

  return true;
}