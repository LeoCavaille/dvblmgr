#include "heartbeat.hpp"
#include "machine.h"

Heartbeat::Heartbeat(const MachinePtr &mPtr) {
	type_ = Type_;
	recipient_ = mPtr->getID();
	message_ = "ZGUEG - T KI LOL ?";
}
