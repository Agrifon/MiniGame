#ifndef APPLICATION_H
#define APPLICATION_H

#include "main.h"
#include "player.h"
#include "pongBall.h"
#include "IServer.h"

void server_accept(I_server* server, Player* player2);

class Application
{
protected:
	sf::RenderWindow* window;

	bool isServer;

	Player* player1;
	Player* player2;

	PongBall* pongBall;

	I_server* server;
	I_server* client;

	sf::Clock clock;
	float time;

	void isOpenf();

public:
	Application(char mode);
	~Application();
	void init();
	void run();
	void end();
};

#endif