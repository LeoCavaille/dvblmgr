#ifndef SERVERRUNNER_HPP_
#define SERVERRUNNER_HPP_

#include "ptr/configuration.hpp"
#include "commanddispatcher_ptr.hpp"
#include "broadcastlistgenerator_ptr.hpp"
#include "watchdog_ptr.hpp"

#include <mutex>
#include <string>

#include <boost/asio/io_service.hpp>

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
	void startWatchdog();
	void stopWatchdog();


	ConfigurationPtr configPtr_;
	CommandDispatcherPtr commandDispatcherPtr_;
	BroadcastListGeneratorPtr broadcastListGeneratorPtr_;
	WatchdogPtr watchdogPtr_;

	std::mutex mutex_;
	bool stopFlag_;

	boost::asio::io_service& b_ioService_;

};




#endif /* SERVERRUNNER_HPP_ */
