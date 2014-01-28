#include "clientsession.hpp"


ClientSession::ClientSession(boost::asio::io_service& ioService) : b_socket_(ioService)
{}

boost::asio::ip::tcp::socket& ClientSession::getSocket()
{
	return b_socket_;
}

void ClientSession::start()
{
	std::cout << "KIKINOULOL" << std::endl;
	//b_socket_.async_read()
}
