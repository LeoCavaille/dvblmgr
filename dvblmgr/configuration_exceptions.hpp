#ifndef CONFIGURATION_EXCEPTIONS_HPP_
#define CONFIGURATION_EXCEPTIONS_HPP_

class ConfigurationException {

};

class ConfigurationFileUnreachable {
public:
	ConfigurationFileUnreachable(const std::string& filename) : filename_(filename) {}
	const char* what() const {
		std::string msg("Cannot access read/write the config file : ");
		msg.append(filename_);
		return msg.c_str();
	}
private:
	std::string filename_;
};



#endif /* CONFIGURATION_EXCEPTIONS_HPP_ */
