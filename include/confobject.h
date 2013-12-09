#ifndef CONFOBJECT_H_
#define CONFOBJECT_H_

#include "configuration_ptr.h"

class ConfObject {
protected:
	ConfObject();
	ConfObject(const ConfigurationPtr& cPtr);
	void persist();

protected:
	ConfigurationWeakPtr config_;
};

#endif /* CONFOBJECT_H_ */
