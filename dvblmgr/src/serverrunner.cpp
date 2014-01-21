#include "serverrunner.hpp"
#include "commanddispatcher.hpp"

#include "configuration_exceptions.hpp"

#include "configuration.hpp"
#include "broadcastlistgenerator.hpp"
#include "watchdog.hpp"

#include "clientconnection.hpp"

#include <boost/bind.hpp>


ServerRunner::ServerRunner(const std::string& confFile, boost::asio::io_service& ioService, const boost::asio::ip::tcp::endpoint& endpoint) :
stopFlag_(false), b_ioService_(ioService), b_acceptor_(ioService, endpoint)
{
  // Load our configuration
  configPtr_ = std::make_shared<Configuration>(confFile);
  try {
	  configPtr_->load();
  } catch (ConfigurationFileUnreachable &e) {
	  std::cerr << "ERROR: In configuration handling: " << e.what() << std::endl;
	  exit(EXIT_FAILURE);
  }

  // Launch the asynchronous TCP server
  b_tcpThread_ = std::thread(&ServerRunner::waitForConnection, this);

  commandDispatcherPtr_ = std::make_shared<CommandDispatcher>();
  watchdogPtr_ = std::make_shared<Watchdog>(configPtr_, commandDispatcherPtr_);
  broadcastListGeneratorPtr_ = std::make_shared<BroadcastListGenerator>(configPtr_);
}

void ServerRunner::waitForConnection() {
	ClientConnectionPtr newConnectionPtr = std::make_shared<ClientConnection>(b_ioService_);
	b_acceptor_.async_accept(newConnectionPtr->getSocket(), std::bind(&ServerRunner::handleAccept, this, std::placeholders::_1, newConnectionPtr));
}

void ServerRunner::handleAccept(const boost::system::error_code& error, ClientConnectionPtr newConnection) {
	if(! error)
	{
		std::cout << "Connection acceptée de : " << newConnection->getSocket().remote_endpoint().address().to_string() << std::endl;
	}
	else
	{
		std::cerr << "handleAccept failed" << std::endl;
	}
}

void ServerRunner::start() {
	startCommandDispatcher();
	startWatchdog();
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
	stopBroadcastListGenerator();
	stopWatchdog();
	stopCommandDispatcher();
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

void ServerRunner::startWatchdog() {
	watchdogPtr_->start();
}

void ServerRunner::stopWatchdog() {
	watchdogPtr_->stop();
}
