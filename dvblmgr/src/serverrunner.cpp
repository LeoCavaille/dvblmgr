#include "serverrunner.hpp"
#include "commanddispatcher.hpp"

#include "configuration_exceptions.hpp"

#include "configuration.hpp"
#include "broadcastlistgenerator.hpp"
#include "watchdog.hpp"

#include "clientsession.hpp"

#include <boost/bind.hpp>


ServerRunner::ServerRunner(const std::string& confFile, boost::asio::io_service& ioService, const boost::asio::ip::tcp::endpoint& endpoint) :
stopFlag_(false), b_acceptor_(ioService, endpoint)
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
  waitForConnection();

  using ioServiceRunType = std::size_t (boost::asio::io_service::*)(void);
  ioServiceRunType runFunc = &boost::asio::io_service::run;
  b_tcpThread_ = std::thread(runFunc, std::ref(b_acceptor_.get_io_service()));

  commandDispatcherPtr_ = std::make_shared<CommandDispatcher>();
  watchdogPtr_ = std::make_shared<Watchdog>(configPtr_, commandDispatcherPtr_);
  broadcastListGeneratorPtr_ = std::make_shared<BroadcastListGenerator>(configPtr_);

}

void ServerRunner::waitForConnection() {
	ClientSessionPtr newSession = std::make_shared<ClientSession>(b_acceptor_.get_io_service());
	b_acceptor_.async_accept(newSession->getSocket(), std::bind(&ServerRunner::handleAccept, this, std::placeholders::_1, newSession));
}

void ServerRunner::handleAccept(const boost::system::error_code& error, ClientSessionPtr newSession) {
	if(! error)
	{
		std::cout << "Connection acceptée de : " << newSession->getSocket().remote_endpoint().address().to_string() << std::endl;
		newSession->start();
		waitForConnection();
	}
	else
	{
		std::cout << "handleAccept failed" << std::endl;
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
