#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"
#include "globalVariable.h"

class Player
{
private:
	int m_height;
	int m_width;

	float m_posX;
	float m_posY;

	int score = 0;

public:

	Player(int height, int width, float posX, float posY);
	~Player();

	void draw(sf::RenderWindow* window);
	void move(float time);

	friend class PongBall;
};

#endif