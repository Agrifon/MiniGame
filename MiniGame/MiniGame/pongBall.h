#ifndef PONGBALL_H
#define PONGBALL_H

#include "main.h"
#include "player.h"
#include "globalVariable.h"

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
};

void separatorDraw(sf::RenderWindow* window);

#endif 
