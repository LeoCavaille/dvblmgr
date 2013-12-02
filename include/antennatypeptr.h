#ifndef BROADCASTTYPEPTR_H_
#define BROADCASTTYPEPTR_H_

#include <memory>

class BroadcastType;
typedef std::shared_ptr<BroadcastType> BroadcastTypePtr;

bool operator==(const std::shared_ptr<BroadcastType>& lhs, const std::shared_ptr<BroadcastType>& rhs);

#endif /* BROADCASTTYPEPTR_H_ */
