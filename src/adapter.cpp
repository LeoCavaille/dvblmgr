#include "adapter.h"
#include <algorithm>

Adapter::Adapter(const unsigned char &id, const unsigned char &frontendId,
                 const Antenna &antenna, const std::vector<AntennaType> &compat)
    : id_(id), frontendId_(frontendId), antenna_(antenna), compat_(compat) {}

bool Adapter::isCompatible(const AntennaType &at) const {
  auto it = std::find(compat_.begin(), compat_.end(), at);
  return (it != compat_.end());
}
