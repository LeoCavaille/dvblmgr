#include "adapter.hpp"
#include "broadcasttype.hpp"
#include "antenna.hpp"

#include "vectorcompare.hpp"
#include <algorithm>

Adapter::Adapter() {}

Adapter::Adapter(const MachinePtr &mPtr) : machine_(mPtr) {}

Adapter::Adapter(unsigned char id, unsigned char frontendId,
                 const AntennaPtr &antennaPtr,
                 const std::vector<BroadcastTypePtr> &compats)
    : id_(id), frontendId_(frontendId), antennaPtr_(antennaPtr),
      compats_(compats) {}

bool Adapter::isCompatible(const BroadcastTypePtr &bt) const {
  auto it = std::find_if(
                compats_.begin(), compats_.end(),
                [&bt](const BroadcastTypePtr & p) { return *bt == *p; });
  return (it != compats_.end());
}

bool Adapter::operator==(const Adapter &rhs) const {
  return id_ == rhs.id_ && frontendId_ == rhs.frontendId_ &&
         *antennaPtr_ == *(rhs.antennaPtr_) &&
         compareVectorsPtr(compats_, rhs.compats_);
}

MachinePtr Adapter::getMachine() const {
	return machine_.lock();
}