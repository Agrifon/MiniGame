#include "application.h"

Application::Application()
	:window(nullptr)
{

}

Application::~Application()
{

}

void Application::init()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(sf::VideoMode(windows_width, windows_height), "MiniGame", sf::Style::Default, settings);

	player1 = new Player(player_height, player_width, windows_width - 10, windows_height / 2 - player_height / 2);
	player2 = new Player(player_height, player_width, 0,                  windows_height / 2 - player_height / 2);

	pongBall = new PongBall(pongBall_Radius, windows_width/2, windows_height/2);

}

void Application::run()
{
	while (window->isOpen())
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

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

	player1->move(time);
	player2->move(time);
	pongBall->move(time, player1, player2);

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