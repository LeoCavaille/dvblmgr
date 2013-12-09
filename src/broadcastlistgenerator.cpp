#include "broadcastlistgenerator.hpp"
#include "configuration.hpp"
#include "multiplex.h"
#include "machine.h"
#include "adapter.h"

#include "commands/adapterstart.hpp"


void BroadcastListGenerator::mainLoop() {
	while(true) {
		mutex_.lock();
		if(stopSignal_) {
			std::cerr << "INFO: BroadcastListGenerator required to stop, stopping !" << std::endl;
			mutex_.unlock();
			return;
		}
		mutex_.unlock();
		std::cerr << "INFO: BroadcastListGenerator mainLoop reporting" << std::endl;
		if (configurationPtr_->hasChanged()) {
			std::cerr << "INFO: BroadcastListGenerator is generating a new list, WAIT FOR IT" << std::endl;
			configurationPtr_->mChange_.lock();

			Assignement a = generateAssignement();

			configurationPtr_->hasChanged_ = false;
			configurationPtr_->mChange_.unlock();

		}
		std::this_thread::sleep_for(std::chrono::seconds(1));

	}
}

void BroadcastListGenerator::start() {
	std::cerr << "INFO: BroadcastListGenerator starting" << std::endl;
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


  for(auto const &mPtr : configurationPtr_->getMachines()) {
	if (! mPtr->connected())
	  continue;
    for(auto const &aPtr : mPtr->getAdapters()) {
      availableAdapters.push_back(aPtr);
    }
  }

  // Let's allocate multiplex to adapter with less compatibilities first
  std::sort(availableAdapters.begin(), availableAdapters.end(),
    [](const AdapterPtr &a1, const AdapterPtr &a2) {
      return a1->compatibilityCount() > a2->compatibilityCount();
    }
  );

  // Sort multiplexs by priority
  std::sort(multiplexs.begin(), multiplexs.end(), [](const MultiplexPtr &m1, const MultiplexPtr &m2) {
    return m1->getPriority() < m2->getPriority();
  });

  // Assign multiplexs
  for(auto const &m : multiplexs) {
    unsigned int i = 0;
    while(i<availableAdapters.size()) {
      if(availableAdapters[i]->isCompatible(m->getBroadcastType())) {
        // ADD IT
      }
      i++;
    }
  }

  return Assignement();
}
