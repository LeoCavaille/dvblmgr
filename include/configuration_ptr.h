#ifndef CONFIGURATIONPTR_H_
#define CONFIGURATIONPTR_H_

#include <memory>

class Configuration;
typedef std::shared_ptr<Configuration> ConfigurationPtr;
typedef std::weak_ptr<Configuration> ConfigurationWeakPtr;

#endif /* CONFIGURATIONPTR_H_ */
