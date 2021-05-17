#ifndef AISERVER_H
#define AISERVER_H

#include "main.h"

using namespace boost::asio;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

void client_session(socket_ptr sock);

class AI_server
{
protected:
	io_service m_service;
	ip::tcp::endpoint m_ep;
	ip::tcp::acceptor* m_acc;
	socket_ptr m_sock;

public:
	virtual ~AI_server() = 0;
	virtual void send() = 0;
	virtual void accept() = 0;
};

class AI_server_boost_asio : public AI_server
{
public:
	AI_server_boost_asio();
	virtual ~AI_server_boost_asio();
	virtual void send();
	virtual void accept();
};

#endif