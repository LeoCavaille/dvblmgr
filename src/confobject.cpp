#include "confobject.h"
#include "configuration.hpp"

ConfObject::ConfObject() {}

ConfObject::ConfObject(const ConfigurationPtr& cPtr) : config_(cPtr) {}

void ConfObject::persist(){
  auto configPtr = config_.lock();
  assert(configPtr != nullptr);
  configPtr->save();
}
