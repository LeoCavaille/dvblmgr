#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "antennaptr.h"
#include "broadcasttypeptr.h"
#include "confobject.h"

#include <vector>

class Adapter : public ConfObject {
public:
  Adapter();

  bool isCompatible(const BroadcastTypePtr &bt) const;

private:
  unsigned char id_;
  unsigned char frontendId_;
  AntennaPtr antennaPtr_;
  std::vector<BroadcastTypePtr> compats_;
};

#endif /* ADAPTER_H_ */
