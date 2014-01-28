#include "watchdog.hpp"
#include "configuration.hpp"
#include "machine.hpp"
#include "commanddispatcher.hpp"
#include "commands/heartbeat.hpp"

#include <iostream>

void Watchdog::mainLoop() {
  while (true) {
    mStop_.lock();
    if (stopSignal_) {
#ifdef DEBUG
      std::cerr << "INFO: Watchdog required to stop, stopping !" << std::endl;
#endif
      mStop_.unlock();
      return;
    }
    mStop_.unlock();
#ifdef DEBUG
    std::cerr << "INFO: Watchdog mainLoop reporting" << std::endl;
#endif

    // Request the status of all connected machines
    for (auto const &m : configurationPtr_->getMachines()) {
      if (!m->connected())
        continue;
      std::shared_ptr<Heartbeat> cPtr = std::make_shared<Heartbeat>(m);
      cdPtr_->queue(std::dynamic_pointer_cast<Command>(cPtr));
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void Watchdog::start() {
#ifdef DEBUG
  std::cerr << "INFO: Watchdog starting" << std::endl;
#endif
  watchdogThread_ = std::thread(&Watchdog::mainLoop, this);
}

void Watchdog::stop() {
  mStop_.lock();
  stopSignal_ = true;
  mStop_.unlock();
  watchdogThread_.join();
}
