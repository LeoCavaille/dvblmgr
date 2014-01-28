#ifndef BROADCASTLISTGENERATOR_H_
#define BROADCASTLISTGENERATOR_H_

#include "ptr/configuration.hpp"
#include "ptr/adapter.hpp"
#include "ptr/multiplex.hpp"
#include <map>

#include <mutex>
#include <thread>


typedef std::map<AdapterPtr, MultiplexPtr> Assignement;

class BroadcastListGenerator {
public:
  BroadcastListGenerator() {};
  BroadcastListGenerator(ConfigurationPtr configurationPtr)
    : configurationPtr_(configurationPtr), offline_(false), stopSignal_(false) {};

  Assignement generateAssignement();
  void updateAssignement(const Assignement& map); // Et un dispatcher

  void start();
  void stop();

  void setOffline(bool offline) { offline_ = offline; };

private:
  void mainLoop();

  Assignement assignement_;
  ConfigurationPtr configurationPtr_;

  bool offline_;
  std::mutex mutex_;
  bool stopSignal_;
  std::thread generatorThread_;
};


#endif /* BROADCASTLISTGENERATOR_H_ */
