#include "broadcastlistgenerator.hpp"
#include "configuration.hpp"
#include "multiplex.hpp"
#include "machine.hpp"
#include "adapter.hpp"

#include "commands/adapterstart.hpp"

void BroadcastListGenerator::mainLoop() {
  while (true) {
    mutex_.lock();
    if (stopSignal_) {
#ifdef DEBUG
      std::cerr << "INFO: BroadcastListGenerator required to stop, stopping !"
                << std::endl;
#endif
      mutex_.unlock();
      return;
    }
    mutex_.unlock();
#ifdef DEBUG
    std::cerr << "INFO: BroadcastListGenerator mainLoop reporting" << std::endl;
#endif
    if (configurationPtr_->hasChanged()) {
#ifdef DEBUG
      std::cerr << "INFO: BroadcastListGenerator is generating a new list, "
                   "WAIT FOR IT" << std::endl;
#endif
      configurationPtr_->mChange_.lock();

      Assignement a = generateAssignement();

      configurationPtr_->hasChanged_ = false;
      configurationPtr_->mChange_.unlock();
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void BroadcastListGenerator::start() {
#ifdef DEBUG
  std::cerr << "INFO: BroadcastListGenerator starting" << std::endl;
#endif
  generatorThread_ = std::thread(&BroadcastListGenerator::mainLoop, this);
}

void BroadcastListGenerator::stop() {
  mutex_.lock();
  stopSignal_ = true;
  mutex_.unlock();
  generatorThread_.join();
}

Assignement BroadcastListGenerator::generateAssignement() {
  std::vector<AdapterPtr> availableAdapters;
  std::vector<MultiplexPtr> multiplexs = configurationPtr_->getMultiplexs();
  Assignement assignement;

  for (auto const &mPtr : configurationPtr_->getMachines()) {
    if (offline_ || mPtr->isConnected()) {
      for (auto const &aPtr : mPtr->getAdapters()) {
        availableAdapters.push_back(aPtr);
      }
    }
  }

  // Let's allocate multiplex to adapter with less compatibilities first
  std::sort(availableAdapters.begin(), availableAdapters.end(),
            [](const AdapterPtr &a1, const AdapterPtr &a2) {
    return a1->compatibilityCount() > a2->compatibilityCount();
  });

  // Sort multiplexs by priority
  std::sort(multiplexs.begin(), multiplexs.end(),
            [](const MultiplexPtr &m1, const MultiplexPtr &m2) {
    return m1->getPriority() < m2->getPriority();
  });

  // Assign multiplexs
  for (auto const &m : multiplexs) {
    for (unsigned int i = 0; i < availableAdapters.size(); ++i) {
      if (availableAdapters[i]->isCompatible(m)) {
        assignement.insert(std::make_pair(availableAdapters[i], m));
        availableAdapters.erase(availableAdapters.begin() + i);
        break;
      }
    }
  }

  return assignement;
}
