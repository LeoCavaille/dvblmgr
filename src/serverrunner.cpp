#include "serverrunner.hpp"
#include "commanddispatcher.hpp"

#include "configuration_exceptions.hpp"

#include "configuration.hpp"
#include "broadcastlistgenerator.hpp"


ServerRunner::ServerRunner(const std::string& confFile) :
stopFlag_(false)
{
  // Load our configuration
  configPtr_ = std::make_shared<Configuration>(confFile);
  try {
	  configPtr_->load();
  } catch (ConfigurationFileUnreachable &e) {
	  std::cerr << "ERROR: In configuration handling: " << e.what() << std::endl;
	  exit(EXIT_FAILURE);
  }
  commandDispatcherPtr_ = std::make_shared<CommandDispatcher>();
  broadcastListGeneratorPtr_ = std::make_shared<BroadcastListGenerator>(configPtr_);
}

void ServerRunner::start() {
	startCommandDispatcher();
	startBroadcastListGenerator();
}

void ServerRunner::signalStop() {
	mutex_.lock();
	stopFlag_ = true;
	mutex_.unlock();
}

bool ServerRunner::stopRequired() {
	mutex_.lock();
	bool b = stopFlag_;
	mutex_.unlock();
	return b;
}

void ServerRunner::stop() {
	stopCommandDispatcher();
	stopBroadcastListGenerator();
}

void ServerRunner::startCommandDispatcher() {
	commandDispatcherPtr_->start();
}

void ServerRunner::stopCommandDispatcher() {
	commandDispatcherPtr_->stop();
}

void ServerRunner::startBroadcastListGenerator() {
	broadcastListGeneratorPtr_->start();
}

void ServerRunner::stopBroadcastListGenerator() {
	broadcastListGeneratorPtr_->stop();
}
