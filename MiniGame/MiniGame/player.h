#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"
#include <sstream>

class Player
{
public:
	int m_height;
	int m_width;

	float m_posX;
	float m_posY;

	int m_score = 0;

	sf::Font m_font;
	sf::Text m_text;

//public:

	Player(int height, int width, float posX, float posY);
	~Player();

	void draw(sf::RenderWindow* window);
	void move(float time);
	void initScore(float posX, float posY, int size);

	friend class PongBall;
	friend class I_server_boost_asio;
	friend class I_client_boost_asio;
};

#endif