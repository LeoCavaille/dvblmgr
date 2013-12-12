#include "yaml/adapter.h"
#include "adapter.h"

#include "broadcasttype.h"
#include "antenna.h"


YAML::Node YAML::convert<AdapterPtr>::encode(const AdapterPtr &rhs) {
  Node node;
  node["id"] = rhs->id_;
  node["frontendId"] = rhs->frontendId_;
  for (auto const &btPtr: rhs->compats_)
  {
  	node["broadcastType"].push_back(YAML::convert<BroadcastTypePtr>::encode(btPtr));
  }

  return node;
}

bool YAML::convert<AdapterPtr>::decode(const YAML::Node &node, AdapterPtr &rhs) {
  rhs->id_ = node["id"].as<unsigned char>();
  rhs->frontendId_ = node["frontendId"].as<unsigned char>();
  rhs->antennaPtr_ = std::make_shared<Antenna>();
  YAML::convert<AntennaPtr>::decode(node["antenna"], rhs->antennaPtr_);
  for (auto const &btNode : node["broadcastType"]) {
	BroadcastTypePtr btPtr = std::make_shared<BroadcastType>();
	YAML::convert<BroadcastTypePtr>::decode(btNode, btPtr);
    rhs->compats_.push_back(btPtr);
  }

  return true;
}
