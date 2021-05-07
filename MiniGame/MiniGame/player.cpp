#include "player.h"

Player::Player(int height, int width, float posX, float posY)
	: m_height(height), m_width(width), m_posX(posX), m_posY(posY)
{

}

Player::~Player()
{

}

void Player::draw(sf::RenderWindow* window)
{
	sf::RectangleShape m_rectangle(sf::Vector2f(m_width, m_height));

	m_rectangle.setPosition(m_posX, m_posY);
	m_rectangle.setFillColor(sf::Color::White);

	window->draw(m_rectangle);
}

void Player::move(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_posY > 0)
		{
			m_posY -= 0.5 * time;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (m_posY < windows_height - player_height)
		{
			m_posY += 0.5 * time;
			
		}
	}
}