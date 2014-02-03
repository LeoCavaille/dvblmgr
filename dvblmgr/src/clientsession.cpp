#include "clientsession.hpp"
#include "configuration.hpp"
#include "configuration_exceptions.hpp"

ClientSession::ClientSession(boost::asio::io_service &ioService,
                             ConfigurationPtr configPtr)
    : b_socket_(ioService), configPtr_(configPtr) {}

boost::asio::ip::tcp::socket &ClientSession::getSocket() { return b_socket_; }

void ClientSession::start() {
  b_ipAddress_ = b_socket_.remote_endpoint().address();
  try {
    configPtr_->machineSetConnectedFlag(b_ipAddress_, true);
  }
  catch (ConfigurationMachineUnauthorized &e) {
    std::cerr << e.what() << std::endl;
    stop();
  }
}

void ClientSession::stop() {
  b_socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
  b_socket_.close();
}
