#ifndef CLIENTSESSION_HPP_
#define CLIENTSESSION_HPP_

#include "ptr/configuration.hpp"

#include <boost/asio.hpp>

class ClientSession {
public:
  ClientSession(boost::asio::io_service &ioService, ConfigurationPtr configPtr);

  boost::asio::ip::tcp::socket &getSocket();
  boost::asio::ip::address getIP();

  void start();
  void stop();

private:
  boost::asio::ip::tcp::socket b_socket_;
  ConfigurationPtr configPtr_;

  boost::asio::ip::address b_ipAddress_;
};

#endif /* CLIENTSESSION_HPP_ */
