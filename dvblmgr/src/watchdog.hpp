#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include "ptr/configuration.hpp"
#include "commanddispatcher_ptr.hpp"
#include <map>

#include <mutex>
#include <thread>

class Watchdog {
public:
  Watchdog() {};
  Watchdog(const ConfigurationPtr &configurationPtr,
           const CommandDispatcherPtr &cdPtr)
      : configurationPtr_(configurationPtr), cdPtr_(cdPtr),
        stopSignal_(false) {};

  void start();
  void stop();

private:
  void mainLoop();

  ConfigurationPtr configurationPtr_;
  CommandDispatcherPtr cdPtr_;

  std::mutex mStop_;
  bool stopSignal_;
  std::thread watchdogThread_;
};

#endif /* WATCHDOG_H_ */
