#ifndef BROADCASTLISTGENERATOR_H_
#define BROADCASTLISTGENERATOR_H_

#include "ptr/configuration.h"
#include "ptr/adapter.h"
#include "ptr/multiplex.h"
#include <map>

#include <mutex>
#include <thread>


typedef std::map<AdapterPtr, MultiplexPtr> Assignement;

class BroadcastListGenerator {
public:
  BroadcastListGenerator() {};
  BroadcastListGenerator(ConfigurationPtr configurationPtr)
    : configurationPtr_(configurationPtr), stopSignal_(false) {};

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
