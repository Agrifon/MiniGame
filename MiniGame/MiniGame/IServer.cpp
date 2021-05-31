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

void I_server_boost_asio::accept(Player* player2)
{
	while (!m_connected)
	{
		m_acc->accept(*m_sock);

		std::thread thrSend(client_session_send, std::ref(m_sock), std::ref(m_connected), std::ref(dataServer));
		std::thread thrAccept(client_session_accept, std::ref(m_sock), std::ref(dataServer), std::ref(player2));

		thrSend.join();
		thrAccept.join();
	}
}

void I_server_boost_asio::send(float s_value)
{

}

bool I_server_boost_asio::isConnected()
{
	return m_connected;
}

void I_server_boost_asio::updateData(Player* player1, Player* player2, PongBall* pongBall)
{
	dataServer.m_player1_posX = player1->m_posX;
	dataServer.m_player1_posY = player1->m_posY;
	dataServer.m_player1_score = player1->m_score;

	dataServer.m_player2_posX = player2->m_posX;
	dataServer.m_player2_posY = player2->m_posY;
	dataServer.m_player2_score = player2->m_score;

	dataServer.m_pong_posX = pongBall->m_posX;
	dataServer.m_pong_posY = pongBall->m_posY;
}

void client_session_send(socket_ptr sock, bool& connected, package& data)
{
	std::cout << "connected" << std::endl;
	connected = true;

	while (true)
	{
		std::string strData = data.structToString();

		const char* charData = strData.c_str() + '\0';

		Sleep(1);
		write(*sock, buffer(charData, strData.length() + 1));
	}
}

void client_session_accept(socket_ptr sock, package& data, Player* player2)
{

	while (true)
	{
		char char_s_value[20];
		size_t len = sock->read_some(buffer(char_s_value));
		if (len > 0)
		{
			sock->read_some(buffer(char_s_value));
			std::string str_s_value = char_s_value;

			lerpBegin = player2->getPosY();
			lerpEnd = std::stof(char_s_value);
		}

		while (lerpT <= 1)
		{
			//std::cout << "lerpBegin:"<< " "<< lerpBegin << " ";
			//std::cout << "lerpEnd:" << " " << lerpEnd << " ";
			//std::cout << "lerpT:" << " " << lerpT << std::endl;

			_lock.lock();
			player2->setPosY(lerp(lerpBegin, lerpEnd, lerpT));
			lerpT += 0.05;
			_lock.unlock();
		}
		lerpT = 0;
	}
}

float lerp(float begin, float end, float t)
{
	return begin * (1 - t) + end * t;
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

void I_client_boost_asio::send(const float s_value)
{
	std::string str_s_value = { std::to_string(s_value) + '\0'};
	const char* char_s_value = str_s_value.c_str();

	Sleep(1);
	//std::cout << str_s_value.length() << std::endl;
	write(*m_sock, buffer(char_s_value, str_s_value.length()));
}

void I_client_boost_asio::accept(Player* player2)
{
	
}

bool I_client_boost_asio::isConnected()
{
	return m_connected;
}

void I_client_boost_asio::updateData(Player* player1, Player* player2, PongBall* pongBall)
{
	//прием
	char charData[150];
	size_t len = m_sock->read_some(buffer(charData));
	if (len > 0)
	{
		m_sock->read_some(buffer(charData));

		std::string strData(charData);

		dataClient.stringToStruct(strData);

		_lock.lock();
		player1->m_posX = dataClient.m_player1_posX;
		player1->m_posY = dataClient.m_player1_posY;
		player1->m_score = dataClient.m_player1_score;

		player2->m_posX = dataClient.m_player2_posX;
		player2->m_posY = dataClient.m_player2_posY;
		player2->m_score = dataClient.m_player2_score;

		pongBall->m_posX = dataClient.m_pong_posX;
		pongBall->m_posY = dataClient.m_pong_posY;
		_lock.unlock();
	}
}