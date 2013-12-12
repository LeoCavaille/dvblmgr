#ifndef PTR_CONFIGURATION_HPP_
#define PTR_CONFIGURATION_HPP_

#include <memory>

class Configuration;
typedef std::shared_ptr<Configuration> ConfigurationPtr;
typedef std::weak_ptr<Configuration> ConfigurationWeakPtr;

#endif /* PTR_CONFIGURATION_HPP_ */
