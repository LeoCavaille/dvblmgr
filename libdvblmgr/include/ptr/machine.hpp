#ifndef PTR_MACHINE_HPP_
#define PTR_MACHINE_HPP_

#include <memory>

class Machine;
typedef std::shared_ptr<Machine> MachinePtr;
typedef std::weak_ptr<Machine> MachineWeakPtr;

#endif /* PTR_MACHINE_HPP_ */
