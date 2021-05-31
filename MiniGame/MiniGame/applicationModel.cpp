#include "application.h"

Application::Application(char mode) // model
	:window(nullptr)
{
	if (mode == 's')
	{
		isServer = true;
		std::cout << "Server mode" << std::endl;
		std::cout << "Waiting connect" << std::endl;
	}
	else
	{
		isServer = false;
		std::cout << "Client mode" << std::endl;
	}
}

Application::~Application()
{

}

void Application::init() // model
{
	player1 = new Player(player_height, player_width, windows_width - 10, windows_height / 2 - player_height / 2);
	player2 = new Player(player_height, player_width, 0, windows_height / 2 - player_height / 2);

	if (isServer)
	{
		server = new I_server_boost_asio;
		boost::thread(boost::bind(server_accept, server, player2));
		while (!server->isConnected())
		{
			Sleep(100);
		}
	}
	else
	{
		client = new I_client_boost_asio;
		while (!client->isConnected())
		{
			Sleep(100);
		}
	}

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(sf::VideoMode(windows_width, windows_height), "MiniGame", sf::Style::Default, settings);

	player1->initScore(550, 100, 300);
	player2->initScore(150, 100, 300);

	pongBall = new PongBall(pongBall_Radius, windows_width / 2, windows_height / 2);
}

void Application::end() //model
{
	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}
}

void server_accept(I_server* server, Player* player2)
{
	server->accept(player2);
}