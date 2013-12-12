#ifndef ADAPTER_HPP_
#define ADAPTER_HPP_

#include "ptr/machine.hpp"
#include "ptr/antenna.hpp"
#include "ptr/broadcasttype.hpp"
#include "confobject.hpp"
#include "yaml/adapter.hpp"

#include <vector>

class Adapter : public ConfObject {
public:
  Adapter();
  Adapter(const ConfigurationPtr& cPtr, const MachinePtr &mPtr);
  Adapter(unsigned char id, unsigned char frontendId,
          const AntennaPtr &antennaPtr,
          const std::vector<BroadcastTypePtr> &compats);

  bool isCompatible(const BroadcastTypePtr &bt) const;
  unsigned int compatibilityCount() const { return compats_.size(); };

  MachinePtr getMachine() const;

  bool operator==(const Adapter &rhs) const;

  friend YAML::Node YAML::convert<AdapterPtr>::encode(const AdapterPtr &rhs);
  friend bool YAML::convert<AdapterPtr>::decode(const YAML::Node &node,
                                                AdapterPtr &rhs);

private:
  unsigned char id_;
  unsigned char frontendId_;
  AntennaPtr antennaPtr_;
  std::vector<BroadcastTypePtr> compats_;

  MachineWeakPtr machine_;
};

#endif /* ADAPTER_HPP_ */
