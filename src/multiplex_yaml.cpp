#include "multiplex_yaml.h"
#include "multiplex.h"

#include "antenna_yaml.h"
#include "broadcasttype_yaml.h"
#include "channel.h"


YAML::Node YAML::convert<MultiplexPtr>::encode(const MultiplexPtr &rhs) {
  Node node;
  node["name"] = rhs->name_;
  node["frequency"] = rhs->frequency_;

  return node;
}

/*
 * Not meant to be called directly
 * Should be called from convert<MultiplexTnt>::decode or convert<MultiplexSat>::decode
 */
bool YAML::convert<MultiplexPtr>::decode(const YAML::Node &node, MultiplexPtr rhs) {
  rhs->name_ = node["name"].as<std::string>();
  rhs->frequency_ = node["frequency"].as<unsigned int>();

  rhs->broadcastTypePtr_ = node["broadcastType"].as<BroadcastTypePtr>();

  for(unsigned i=0; i<node["channels"].size(); i++) {
    rhs->channels_.push_back(node["channels"][i].as<ChannelPtr>());
  }

  return true;
}
