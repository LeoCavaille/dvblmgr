#include "adapter.h"
#include <algorithm>

Adapter::Adapter() {}

Adapter::Adapter(unsigned char id, unsigned char frontendId, const AntennaPtr& antennaPtr, const std::vector<BroadcastTypePtr>& compats) :
id_(id),
frontendId_(frontendId),
antennaPtr_(antennaPtr),
compats_(compats)
{}

bool Adapter::isCompatible(const BroadcastTypePtr &bt) const {
  auto it = std::find_if(compats_.begin(), compats_.end(), [&bt](const BroadcastTypePtr& p){return *bt == *p;});
  return (it != compats_.end());
}
