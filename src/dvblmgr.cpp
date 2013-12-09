#include "configuration.hpp"
#include "configuration_ptr.h"

#include "configuration_exceptions.hpp"

int main(int argc, char *argv[]) {

  // FIXME : add long opts, for now we just say that the config file is argv[1]
  std::string confFile;
  if(argc > 1) {
	 confFile = std::string(argv[1]);
  }

  // Load our configuration
  ConfigurationPtr configPtr = std::make_shared<Configuration>(confFile);
  try {
	  configPtr->load();
  } catch (ConfigurationFileUnreachable &e) {
	  std::cerr << "ERROR: In configuration handling: " << e.what() << std::endl;
	  exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
