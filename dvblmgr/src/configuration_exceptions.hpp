#ifndef CONFIGURATION_EXCEPTIONS_HPP_
#define CONFIGURATION_EXCEPTIONS_HPP_

#include <string>

class ConfigurationException {};

class ConfigurationFileUnreachable {
public:
  ConfigurationFileUnreachable(const std::string &filename)
      : filename_(filename) {}
  const char *what() const {
    std::string msg("Cannot access read/write the config file : ");
    msg.append(filename_);
    return msg.c_str();
  }

private:
  std::string filename_;
};

class ConfigurationMachineUnauthorized {
public:
  ConfigurationMachineUnauthorized(const std::string &ip) : ip_(ip) {}
  const char *what() const {
    std::string msg("Connection refused for an unknown IP : ");
    msg.append(ip_);
    msg.append(". Check your configuration.");
    return msg.c_str();
  }

private:
  std::string ip_;
};

#endif /* CONFIGURATION_EXCEPTIONS_HPP_ */
