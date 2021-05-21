#include "IServer.h"

//SERVER
I_server_boost_asio::I_server_boost_asio()
{
	ip::tcp::endpoint ep(ip::tcp::v4(), 2001);
	m_ep = ep;

	m_acc = std::make_unique<ip::tcp::acceptor>(m_service, m_ep);

	socket_ptr sock(new ip::tcp::socket(m_service));
	m_sock = sock;

	m_connected = false;
}

I_server_boost_asio::~I_server_boost_asio()
{

}

void I_server_boost_asio::accept()
{
	while (!m_connected)
	{
		m_acc->accept(*m_sock);

		std::thread thr1(client_session, std::ref(m_sock), std::ref(m_connected), std::ref(dataServer));
		thr1.join();
	}
}

void I_server_boost_asio::send()
{
	boost::asio::write(*m_sock, boost::asio::buffer("ok", 2));
}

bool I_server_boost_asio::isConnected()
{
	return m_connected;
}

void I_server_boost_asio::updateData(Player* player1, Player* player2, PongBall* pongBall)
{
	dataServer.m_player1_posX = player1->m_posX;
	dataServer.m_player1_posY = player1->m_posY;

	dataServer.m_player2_posX = player2->m_posX;
	dataServer.m_player2_posY = player2->m_posY;

	dataServer.m_pong_posX = pongBall->m_posX;
	dataServer.m_pong_posY = pongBall->m_posY;
}

void client_session(socket_ptr sock, bool& connected, package& data)
{
	std::cout << "connected" << std::endl;
	connected = true;

	while (true)
	{
		std::string strData = data.structToString();

		const char* charData = strData.c_str() + '\0';
		
		//std::cout << charData << std::endl;

		Sleep(20);
		write(*sock, buffer(charData, strData.length() + 1));
	}
}

//CLIENT

I_client_boost_asio::I_client_boost_asio()
{
	m_connected = false;

	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001); //адресс подключения
	m_ep = ep;

	socket_ptr sock(new ip::tcp::socket(m_service)); // сокет клиента
	m_sock = sock;

	m_sock->connect(ep);

	m_connected = true;
}

I_client_boost_asio::~I_client_boost_asio()
{

}

void I_client_boost_asio::send()
{

}

void I_client_boost_asio::accept()
{
	
}

bool I_client_boost_asio::isConnected()
{
	return m_connected;
}

void I_client_boost_asio::updateData(Player* player1, Player* player2, PongBall* pongBall)
{
	char charData[100];

	m_sock->read_some(buffer(charData));

	std::string strData(charData);

	dataClient.stringToStruct(strData);

	//std::cout << strData << std::endl;

	player1->m_posX = dataClient.m_player1_posX;
	player1->m_posY = dataClient.m_player1_posY;

	player2->m_posX = dataClient.m_player2_posX;
	player2->m_posY = dataClient.m_player2_posY;

	pongBall->m_posX = dataClient.m_pong_posX;
	pongBall->m_posY = dataClient.m_pong_posY;
}