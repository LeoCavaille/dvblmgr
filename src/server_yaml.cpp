#include "server_yaml.h"
#include "server.h"

#include "adapter.h"

YAML::Node YAML::convert<ServerPtr>::encode(const ServerPtr &rhs) {
  Node node;
  node["name"] = rhs->name_;
  for (auto& aPtr: rhs->adapters_){
    node["adapters"].push_back(YAML::convert<AdapterPtr>::encode(aPtr));
  }

  return node;
}

bool YAML::convert<ServerPtr>::decode(const YAML::Node &node, ServerPtr &rhs) {
  rhs->name_ = node["name"].as<std::string>();
  for(auto &adapterNode : node["adapters"]){
    AdapterPtr aPtr = std::make_shared<Adapter>();
    YAML::convert<AdapterPtr>::decode(adapterNode, aPtr);
    rhs->adapters_.push_back(aPtr);
  }

  return true;
}
