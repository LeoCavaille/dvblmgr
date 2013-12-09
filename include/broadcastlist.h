#ifndef BROADCASTLIST_H_
#define BROADCASTLIST_H_

#include "configuration_ptr.h"
#include "adapter_ptr.h"
#include "multiplex_ptr.h"
#include <map>


typedef std::map<AdapterPtr, MultiplexPtr> Assignement;

class BroadcastList {
public:
  BroadcastList() {};
  BroadcastList(ConfigurationPtr configurationPtr)
    : configurationPtr_(configurationPtr) {};

  Assignement generateAssignement();
  void updateAssignement(const Assignement map); // Et un dispatcher

private:
  Assignement assignement_;
  ConfigurationPtr configurationPtr_;
};


#endif /* BROADCASTLIST_H_ */
