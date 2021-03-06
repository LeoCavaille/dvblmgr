#include "yaml/machine.hpp"
#include "machine.hpp"

#include "adapter.hpp"

YAML::Node YAML::convert<MachinePtr>::encode(const MachinePtr &rhs) {
  Node node;
  node["name"] = rhs->name_;
  node["ip"] = rhs->ip_;
  for (auto& aPtr: rhs->adapters_){
    node["adapters"].push_back(YAML::convert<AdapterPtr>::encode(aPtr));
  }

  return node;
}

bool YAML::convert<MachinePtr>::decode(const YAML::Node &node, MachinePtr &rhs) {
  rhs->name_ = node["name"].as<std::string>();
  rhs->ip_ = node["ip"].as<std::string>();
  for(auto &adapterNode : node["adapters"]){
    AdapterPtr aPtr = std::make_shared<Adapter>(rhs);
    YAML::convert<AdapterPtr>::decode(adapterNode, aPtr);
    rhs->adapters_.push_back(aPtr);
  }

  return true;
}
