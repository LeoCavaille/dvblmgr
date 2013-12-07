#include "multiplexsat.h"
#include "multiplexsat_yaml.h"

YAML::Node YAML::convert<MultiplexSat>::encode(const MultiplexPtr &rhs) {
  Node node;
  return node;
}

bool YAML::convert<MultiplexSat>::decode(const YAML::Node &node, MultiplexPtr &rhs) {
  MultiplexPtr m = std::make_shared<MultiplexSat>();
  YAML::convert<MultiplexPtr>::decode(node, m);

  // TODO
  // Then SAT specific parsing

  // rhs->name_ = node["name"].as<std::string>();
  // rhs->frequency_ = node["frequency"].as<unsigned int>();

  // rhs->broadcastTypePtr_ = node["broadcastType"].as<BroadcastTypePtr>();

  // for(unsigned i=0; i<node["channels"].size(); i++) {
  //   rhs->channels_.push_back(node["channels"][i].as<ChannelPtr>());
  // }

  return true;
}