#pragma once
/*
 #include <iostream>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

#include <boost/thread.hpp>
#include <boost/bind/placeholders.hpp>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

void client_session(socket_ptr sock);

int main(int argc, char* argv[])
{
	using namespace  boost::asio;

	io_service service;
	ip::tcp::endpoint ep(ip::tcp::v4(), 2001); // listen on 2001
	ip::tcp::acceptor acc(service, ep);

	while (true)
	{
		socket_ptr sock(new ip::tcp::socket(service));
		acc.accept(*sock);
		boost::thread(boost::bind(client_session, sock));
	}

	return 0;
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
*/