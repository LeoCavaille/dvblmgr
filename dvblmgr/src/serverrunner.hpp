#ifndef SERVERRUNNER_HPP_
#define SERVERRUNNER_HPP_

#include "ptr/configuration.hpp"
#include "commanddispatcher_ptr.hpp"
#include "broadcastlistgenerator_ptr.hpp"
#include "watchdog_ptr.hpp"
#include "clientsession_ptr.hpp"

#include <mutex>
#include <thread>
#include <string>

#include <boost/asio.hpp>

class ServerRunner {
public:
  ServerRunner(const std::string &confFile, boost::asio::io_service &ioService,
               const boost::asio::ip::tcp::endpoint &endpoint);
  void start();
  void stop();

  void signalStop();
  bool stopRequired();

private:
  void waitForConnection();
  void handleAccept(const boost::system::error_code &error,
                    ClientSessionPtr newConnenction);
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

  std::thread b_tcpThread_;
  boost::asio::ip::tcp::acceptor b_acceptor_;
};

#endif /* SERVERRUNNER_HPP_ */
