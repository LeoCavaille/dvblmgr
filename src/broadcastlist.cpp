#include "broadcastlist.h"
#include "configuration.hpp"
#include "multiplex.h"
#include "machine.h"
#include "adapter.h"

Assignement BroadcastList::generateAssignement() {
  std::vector<AdapterPtr> availableAdapters;
  std::vector<MultiplexPtr> multiplexs = (*configurationPtr_).getMultiplexs();


  for(auto const &m : (*configurationPtr_).getMachines()) {
    for(auto const &a : (*m).getAdapters()) {
      availableAdapters.push_back(a);
    }
  }

  // Let's allocate multiplex to adapter with less compatibilities first
  std::sort(availableAdapters.begin(), availableAdapters.end(),
    [](AdapterPtr a1, AdapterPtr a2) {
      return (*a1).compatibilityCount() > (*a2).compatibilityCount();
    }
  );

  // Sort multiplexs by priority
  std::sort(multiplexs.begin(), multiplexs.end(), [](MultiplexPtr m1, MultiplexPtr m2) {
    return (*m1).getPriority() < (*m2).getPriority();
  });

  // Assign multiplexs
  for(auto const &m : multiplexs) {
    unsigned int i = 0;
    while(i<availableAdapters.size()) {
      if(availableAdapters[i].isCompatible(m.getBroadcastType())) {
        // ADD IT
      }
      i++;
    }
  }

  return Assignement();
}
