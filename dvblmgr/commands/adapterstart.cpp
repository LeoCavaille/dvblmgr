#include "adapterstart.hpp"
#include "adapter.hpp"
#include "machine.hpp"

AdapterStartCommand::AdapterStartCommand(const AdapterPtr &aPtr, const MultiplexPtr &mPtr) {
	type_ = Type_;
	recipient_ = aPtr->getMachine()->getID();
	message_ = "STARTMEUP !";
}
