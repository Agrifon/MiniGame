#ifndef APPLICATION_H
#define APPLICATION_H

#include "main.h"
#include "player.h"
#include "globalVariable.h"
#include "pongBall.h"

class Application
{
protected:
	sf::RenderWindow* window;

	Player* player1;
	Player* player2;

	PongBall* pongBall;

	sf::Clock clock;
	float time;

	void isOpenf();

public:
	Application();
	~Application();
	void init();
	void run();
	void end();
};

#endif