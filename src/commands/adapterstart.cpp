#include "adapterstart.hpp"
#include "adapter.h"
#include "machine.h"

AdapterStartCommand::AdapterStartCommand(const AdapterPtr &aPtr, const MultiplexPtr &mPtr) {
	type_ = Type_;
	recipient_ = aPtr->getMachine()->getID();
	message_ = "STARTMEUP !";
}
