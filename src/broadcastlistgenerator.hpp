#ifndef BROADCASTLISTGENERATOR_H_
#define BROADCASTLISTGENERATOR_H_

#include "configuration_ptr.h"
#include "adapter_ptr.h"
#include "multiplex_ptr.h"
#include <map>

#include <mutex>
#include <thread>


typedef std::map<AdapterPtr, MultiplexPtr> Assignement;

class BroadcastListGenerator {
public:
  BroadcastListGenerator() {};
  BroadcastListGenerator(ConfigurationPtr configurationPtr)
    : configurationPtr_(configurationPtr) {};

  Assignement generateAssignement();
  void updateAssignement(const Assignement& map); // Et un dispatcher

  void start();
  void stop();


private:
  void mainLoop();

  Assignement assignement_;
  ConfigurationPtr configurationPtr_;

  std::mutex mutex_;
  bool stopSignal_;
  std::thread generatorThread_;
};


#endif /* BROADCASTLISTGENERATOR_H_ */
