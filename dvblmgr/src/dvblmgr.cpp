#include "serverrunner.hpp"

#include <thread>
#include <csignal>

ServerRunner * sr = nullptr;

void signalHandler (int signum) {
	if (signum == SIGINT) {
		if (sr) {
			sr->signalStop();
		}
		else {
			exit(EXIT_SUCCESS);
		}
	}
}


int main(int argc, char *argv[]) {

  signal(SIGINT, signalHandler);

  // FIXME : add long opts, for now we just say that the config file is argv[1]
  std::string confFile;
  if(argc > 1) {
	 confFile = std::string(argv[1]);
  }

  boost::asio::io_service io_service;
  tcp::endpoint endpoint(tcp::v4(), 4242);

  sr = new ServerRunner(confFile, io_service, endpoint);
  sr->start();

  while(true) {
	  if (sr->stopRequired()) {
		  sr->stop();
		  break;
	  }
	  std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
