#ifndef SERVERRUNNER_HPP_
#define SERVERRUNNER_HPP_

#include "configuration_ptr.h"
#include "commanddispatcher_ptr.hpp"
#include "broadcastlistgenerator_ptr.hpp"

#include <mutex>
#include <string>

class ServerRunner {
public:
	ServerRunner(const std::string& confFile);
	void start();
	void stop();

	void signalStop();
	bool stopRequired();

private:
	void startCommandDispatcher();
	void stopCommandDispatcher();
	void startBroadcastListGenerator();
	void stopBroadcastListGenerator();


	ConfigurationPtr configPtr_;
	CommandDispatcherPtr commandDispatcherPtr_;
	BroadcastListGeneratorPtr broadcastListGeneratorPtr_;

	std::mutex mutex_;
	bool stopFlag_;
};




#endif /* SERVERRUNNER_HPP_ */
