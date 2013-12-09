#ifndef MACHINEPTR_H_
#define MACHINEPTR_H_

#include <memory>

class Machine;
typedef std::shared_ptr<Machine> MachinePtr;
typedef std::weak_ptr<Machine> MachineWeakPtr;

#endif /* MACHINEPTR_H_ */
