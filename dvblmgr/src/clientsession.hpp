#ifndef CLIENTSESSION_HPP_
#define CLIENTSESSION_HPP_

#include <boost/asio.hpp>

class ClientSession
{
public:
	ClientSession(boost::asio::io_service& ioService);

	boost::asio::ip::tcp::socket& getSocket();
	void start();

private:
	boost::asio::ip::tcp::socket b_socket_;
};

#endif /* CLIENTSESSION_HPP_ */
