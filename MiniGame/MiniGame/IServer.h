#ifndef ISERVER_H
#define ISERVER_H

#include "main.h"
#include "dataPackage.h"
#include "player.h"
#include "pongBall.h"

using namespace boost::asio;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

void client_session_send(socket_ptr sock, bool& connected, package& data);
void client_session_accept(socket_ptr sock, package& data, Player* player2);
//SERVER
class I_server
{
public:
	virtual void send(float s_value) = 0;
	virtual void accept(Player* player2) = 0;

	virtual bool isConnected() = 0;

	virtual void updateData(Player* player1 = nullptr, Player* player2 = nullptr, PongBall* pongBall = nullptr) = 0;
};

class I_server_boost_asio : public I_server
{
protected:
	io_service m_service;
	ip::tcp::endpoint m_ep;
	std::unique_ptr<ip::tcp::acceptor> m_acc;
	socket_ptr m_sock;

	bool m_connected;

	package dataServer;

public:
	I_server_boost_asio();
	virtual ~I_server_boost_asio();
	virtual void send(float s_value);
	virtual void accept(Player* player2);

	virtual bool isConnected();
	virtual void updateData(Player* player1, Player* player2, PongBall* pongBall);
};

//CLIENT
class I_client_boost_asio : public I_server
{
protected:
	io_service m_service;
	ip::tcp::endpoint m_ep;
	socket_ptr m_sock;

	bool m_connected;

	package dataClient;

public:
	I_client_boost_asio();
	virtual ~I_client_boost_asio();
	virtual void send(float s_value);
	virtual void accept(Player* player2);

	virtual bool isConnected();

	virtual void updateData(Player* player1, Player* player2, PongBall* pongBall);

};

#endif