#include "broadcasttypeptr.h"

bool operator==(const std::shared_ptr<BroadcastType>& lhs, const std::shared_ptr<BroadcastType>& rhs)
{
	return (*lhs == *rhs);
}
