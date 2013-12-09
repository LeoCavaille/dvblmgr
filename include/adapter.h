#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "antenna_ptr.h"
#include "broadcasttype_ptr.h"
#include "confobject.h"
#include "adapter_yaml.h"

#include <vector>

class Adapter : public ConfObject {
public:
  Adapter();
  Adapter(const ConfigurationPtr& cPtr);
  Adapter(unsigned char id, unsigned char frontendId,
          const AntennaPtr &antennaPtr,
          const std::vector<BroadcastTypePtr> &compats);

  bool isCompatible(const BroadcastTypePtr &bt) const;

  bool operator==(const Adapter &rhs) const;

  friend YAML::Node YAML::convert<AdapterPtr>::encode(const AdapterPtr &rhs);
  friend bool YAML::convert<AdapterPtr>::decode(const YAML::Node &node,
                                                AdapterPtr &rhs);

private:
  unsigned char id_;
  unsigned char frontendId_;
  AntennaPtr antennaPtr_;
  std::vector<BroadcastTypePtr> compats_;
};

#endif /* ADAPTER_H_ */
