#include "yaml/multiplex.hpp"
#include "multiplex.hpp"

#include "yaml/antenna.hpp"
#include "broadcasttype.hpp"
#include "channel.hpp"


YAML::Node YAML::convert<MultiplexPtr>::encode(const MultiplexPtr &rhs) {
  Node node;
  node["name"] = rhs->name_;
  node["frequency"] = rhs->frequency_;

  node["broadcastType"] = YAML::convert<BroadcastTypePtr>::encode(rhs->broadcastTypePtr_);

  for(auto &c : rhs->channels_) {
     node["channel"].push_back(YAML::convert<ChannelPtr>::encode(c));
   }

  return node;
}

/*
 * Not meant to be called directly
 * Should be called from convert<MultiplexTnt>::decode or convert<MultiplexSat>::decode
 */
bool YAML::convert<MultiplexPtr>::decode(const YAML::Node &node, MultiplexPtr rhs) {
  rhs->name_ = node["name"].as<std::string>();
  rhs->frequency_ = node["frequency"].as<unsigned int>();

  rhs->broadcastTypePtr_ = std::make_shared<BroadcastType>();
  YAML::convert<BroadcastTypePtr>::decode(node["broadcastType"], rhs->broadcastTypePtr_);

  for(auto &n : node["channels"]) {
    ChannelPtr p = std::make_shared<Channel>();
    YAML::convert<ChannelPtr>::decode(n, p);
    rhs->channels_.push_back(p);
  }

  return true;
}
