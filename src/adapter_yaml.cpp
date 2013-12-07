#include "adapter_yaml.h"
#include "adapter.h"

#include "antenna_yaml.h"
#include "broadcasttype_yaml.h"


YAML::Node YAML::convert<AdapterPtr>::encode(const AdapterPtr &rhs) {
  Node node;
  node["id"] = rhs->id_;
  node["frontendId"] = rhs->frontendId_;
  for (auto& btPtr: rhs->compats_)
  {
  	node["broadcastType"].push_back(YAML::convert<BroadcastTypePtr>::encode(btPtr));
  }

  return node;
}

bool YAML::convert<AdapterPtr>::decode(const YAML::Node &node, AdapterPtr &rhs) {
  rhs->id_ = node["id"].as<unsigned int>();
  rhs->frontendId_ = node["frontendId"].as<unsigned int>();
  rhs->antennaPtr_ = node["antenna"].as<AntennaPtr>();
  for (const_iterator it = node["broadcastType"].begin(); it != node["broadcastType"].end();
      ++it) {
    rhs->compats_.push_back(it->as<BroadcastTypePtr>());
  }

  return true;
}