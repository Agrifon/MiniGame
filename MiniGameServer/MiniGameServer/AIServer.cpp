#include "AIServer.h"

AI_server_boost_asio::AI_server_boost_asio()
{
	ip::tcp::endpoint ep(ip::tcp::v4(), 2001);
	m_ep = ep;

	ip::tcp::acceptor acc(m_service, m_ep);
	m_acc = &acc;
	socket_ptr sock(new ip::tcp::socket(m_service));
	m_sock = sock;
}

void AI_server_boost_asio::accept()
{
	while (true)
	{
		m_acc->accept(*m_sock);
		boost::thread(boost::bind(client_session, m_sock));
	}

}

void AI_server_boost_asio::send()
{
	while (true)
	{
		char data[512];
		size_t len = m_sock->read_some(boost::asio::buffer(data));
		if (len > 0)
		boost::asio::write(*m_sock, boost::asio::buffer("ok", 2));
	}
}

void client_session(socket_ptr sock)
{
	while (true)
	{
		char data[512];
		size_t len = sock->read_some(boost::asio::buffer(data));
		if (len > 0)
			boost::asio::write(*sock, boost::asio::buffer("ok", 2));
	}
}