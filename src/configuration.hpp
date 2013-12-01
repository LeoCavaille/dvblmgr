#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <string>

class Configuration {
public:
	Configuration(const std::string& filename);
    void parse();

private:
	std::string filename_;
    YAML::Node config_;
};

#endif /* CONFIGURATION_H_ */
