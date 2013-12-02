#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "antennaptr.h"
#include "confobject.h"
#include "broadcasttype.h"

#include <memory>
#include <vector>

typedef std::shared_ptr<BroadcastType> BroadcastTypePtr;

class Adapter : public ConfObject {
public:
  Adapter();
  Adapter(unsigned char id, unsigned char frontendId, const AntennaPtr& antennaPtr, const std::vector<BroadcastTypePtr>& compats);

  bool isCompatible(const BroadcastTypePtr &bt) const;

private:
  unsigned char id_;
  unsigned char frontendId_;
  AntennaPtr antennaPtr_;
  std::vector<BroadcastTypePtr> compats_;
};

#endif /* ADAPTER_H_ */
