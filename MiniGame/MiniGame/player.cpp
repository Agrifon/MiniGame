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

	std::ostringstream playerScoreString;
	playerScoreString << m_score;
	m_text.setString(playerScoreString.str());

	window->draw(m_text);
	window->draw(m_rectangle);
}

void Player::move(const float time, const bool isServer)
{
	if (isServer)
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
}

float Player::move(const float time)
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (m_posY > 0)
			{
				float temp_m_posY = m_posY;
				temp_m_posY -= 0.5 * time;
				return temp_m_posY;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (m_posY < windows_height - player_height)
			{
				float temp_m_posY = m_posY;
				temp_m_posY += 0.5 * time;
				return temp_m_posY;
			}
		}
		return m_posY;
}

void Player::initScore(float posX, float posY, int size)
{
	m_font.loadFromFile("C:/git/MiniGame/MiniGame/font/CyrilicOld.ttf");
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color(255,255,255,100));
	m_text.setPosition(sf::Vector2f(posX, posY));

	m_text.setCharacterSize(size);

	m_text.setString("0");
}

void Player::setPosY(float Y)
{
	m_posY = Y;
}