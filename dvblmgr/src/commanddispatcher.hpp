#ifndef COMMANDDISPATCHER_HPP_
#define COMMANDDISPATCHER_HPP_

#include "command_ptr.hpp"

#include <thread>
#include <mutex>
#include <deque>

class CommandDispatcher {
public:
  CommandDispatcher();
  void queue(const CommandPtr &c);
  void start();
  void stop();

private:
  void mainLoop();
  bool gotCommands() const;
  void launchCommands();

  std::mutex mutex_;
  bool stopSignal_;
  std::thread dispatcherThread_;

  std::deque<CommandPtr> commands_;
};

#endif /* COMMANDDISPATCHER_HPP_ */
