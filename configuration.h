#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <string>

class Configuration {
public:
	Configuration(const std::string& filename);


private:
	std::string filename_;
};

#endif /* CONFIGURATION_H_ */
