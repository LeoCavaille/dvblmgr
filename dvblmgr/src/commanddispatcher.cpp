#include "commanddispatcher.hpp"

#include "command.hpp"

CommandDispatcher::CommandDispatcher(ConfigurationPtr cPtr): configPtr_(cPtr){
	for (auto &m : cPtr->getMachines()) {
		commands_[m] = std::deque<CommandPtr>();
	}
}

void reloadMachines() {
	for (auto &m : cPtr->getMachines()) {

		commands_[m] = std::deque<CommandPtr>();
	}
}

void CommandDispatcher::queue(const MachinePtr &mPtr, const CommandPtr &cPtr) {
  mutex_.lock();
  commands_[mPtr].push_back(cPtr);
  mutex_.unlock();
}

bool CommandDispatcher::gotCommands(const MachinePtr &mPtr) const { return commands_[mPtr].size() != 0; }

void CommandDispatcher::popCommand(const MachinePtr &mPtr) {
  mutex_.lock();
  commands_[mPtr].pop_front();
  mutex_.unlock();
}
