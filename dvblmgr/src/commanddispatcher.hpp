#ifndef COMMANDDISPATCHER_HPP_
#define COMMANDDISPATCHER_HPP_

#include "command_ptr.hpp"
#include "ptr/machine.hpp"

#include <mutex>
#include <deque>

class CommandDispatcher {
public:
  CommandDispatcher(ConfigurationPtr cPtr);
  void queue(const MachinePtr &mPtr, const CommandPtr &c);
  void reloadMachines();
  bool gotCommands(const MachinePtr &mPtr) const;
  void popCommand(const MachinePtr &mPtr);

private:
  ConfigurationPtr configPtr_;
  std::mutex mutex_;
  std::map<MachinePtr, std::deque<CommandPtr>> commands_;
};

#endif /* COMMANDDISPATCHER_HPP_ */
