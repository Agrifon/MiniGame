#include "application.h"

void Application::run() //controller
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

void Application::isOpenf() // controller + view
{
	window->clear(sf::Color::Black);
	//std::cout << "P1:"<< " "<< player1->getPosY() << " ";
	//std::cout << "P2:" << " " << player2->getPosY() << std::endl;

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

	draw();
}