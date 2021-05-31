#include "application.h"

void Application::draw()
{
	player1->draw(window);
	player2->draw(window);
	pongBall->draw(window);

	window->display();
}