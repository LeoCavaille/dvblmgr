#ifndef CLIENTCONNECTION_HPP_
#define CLIENTCONNECTION_HPP_

#include <boost/asio.hpp>

class ClientConnection
{
public:
	ClientConnection(boost::asio::io_service& ioService);

	boost::asio::ip::tcp::socket& getSocket();

private:
	boost::asio::ip::tcp::socket b_socket_;
};

#endif /* CLIENTCONNECTION_HPP_ */
