#include "adapter.h"
#include <algorithm>

Adapter::Adapter() {}

bool Adapter::isCompatible(const BroadcastTypePtr &bt) const {
  auto it = std::find(compats_.begin(), compats_.end(), bt);
  return (it != compats_.end());
}
