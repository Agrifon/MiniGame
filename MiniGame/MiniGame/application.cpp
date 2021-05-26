#include "application.h"

Application::Application(char mode)
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

void Application::init()
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

	pongBall = new PongBall(pongBall_Radius, windows_width/2, windows_height/2);
}

void Application::run()
{
	while (window->isOpen())
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800; //time /= 800;

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
		}

		isOpenf();
	}
}

void Application::isOpenf()
{
	window->clear(sf::Color::Black);
	std::cout << "P1:"<< " "<< player1->getPosY() << " ";
	std::cout << "P2:" << " " << player2->getPosY() << std::endl;
	if (isServer)
	{
		if (window->hasFocus())
		{
			player1->move(time, isServer);
		}

		pongBall->move(time, player1, player2);
	}
	else
	{
		if (window->hasFocus())
		{
			if (player2->move(time) != player2->getPosY())
			{
				client->send(player2->move(time));
				//std::cout << player2->move(time) << std::endl;
			}
		}
	}

	if (isServer)
	{
		server->updateData(player1, player2, pongBall); //Сервер сохраняет в себя данные
	}
	else
	{
		client->updateData(player1, player2, pongBall); //получение данных с сервера
	}

	player1->draw(window);
	player2->draw(window);
	pongBall->draw(window);

	window->display();
}

void Application::end()
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