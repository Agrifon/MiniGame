#ifndef PONGBALL_H
#define PONGBALL_H

#include "main.h"
#include "player.h"

class PongBall
{
private:
	int m_radius;

	float m_posX;
	float m_posY;

	float m_xSpeed = 0.3;
	float m_ySpeed = 0.2;

	float wait = 0;

	bool isDead = false;

public:
	PongBall(int radius, float posX, float posY);
	~PongBall();
	void draw(sf::RenderWindow* window);
	void move(float time, Player* p1, Player* p2);

	friend class I_server_boost_asio;
	friend class I_client_boost_asio;
};

void separatorDraw(sf::RenderWindow* window);

#endif 
