#include "clientconnection.hpp"


ClientConnection::ClientConnection(boost::asio::io_service& ioService) : b_socket_(ioService)
{}

boost::asio::ip::tcp::socket& ClientConnection::getSocket()
{
	return b_socket_;
}
