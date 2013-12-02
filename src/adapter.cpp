#include "adapter.h"
#include <algorithm>

Adapter::Adapter() {}

bool Adapter::isCompatible(const BroadcastTypePtr &bt) const {
  auto it = std::find_if(compats_.begin(), compats_.end(), [&bt](const BroadcastTypePtr& p){return *bt == *p;});
  return (it != compats_.end());
}
