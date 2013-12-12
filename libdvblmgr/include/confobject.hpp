#ifndef CONFOBJECT_HPP_
#define CONFOBJECT_HPP_

#include "ptr/configuration.hpp"

class ConfObject {
protected:
	ConfObject();
	ConfObject(const ConfigurationPtr& cPtr);
	void persist();

protected:
	ConfigurationWeakPtr config_;
};

#endif /* CONFOBJECT_H_ */
