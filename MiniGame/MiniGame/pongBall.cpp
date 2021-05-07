#include "pongBall.h"

PongBall::PongBall(int radius, float posX, float posY)
	: m_radius(radius), m_posX(posX), m_posY(posY)
{

}

PongBall::~PongBall()
{

}

void PongBall::draw(sf::RenderWindow* window)
{
	sf::CircleShape m_circle(m_radius);
	m_circle.setFillColor(sf::Color::White);
	m_circle.setPosition(m_posX, m_posY);

	window->draw(m_circle);
}

void PongBall::move(float time, Player* p1, Player* p2)
{
	m_posX += m_xSpeed * time;
	m_posY += m_ySpeed * time;

	if (m_posX < player_width) // шарик у левой стенки
	{
		if (m_posY > p2->m_posY && m_posY < p2->m_posY + p2->m_height && !isDead) // платформа по координатам шарика и шарик не вылетел
		{
			m_xSpeed *= -1;
			m_posX = player_width;
		}
		else // не словил шарик
		{
			isDead = true;
			if (wait < timeDeath)
			{
				std::cout << wait << std::endl;
				wait += time;
			}
			else
			{
				isDead = false;
				wait = 0;
				std::cout << "SMEEEEERT" << std::endl;
				m_posX = windows_width / 2;
				m_posY = windows_height / 2;
			}
		}
	}
	if (m_posX > windows_width - pongBall_Radius * 2 - player_width) //шарик у правой стенки
	{
		if (m_posY > p2->m_posY && m_posY < p2->m_posY + p2->m_height && !isDead) // платформа по координатам шарика и шарик не вылетел
		{
			m_xSpeed *= -1;
			m_posX = windows_width - pongBall_Radius * 2 - player_width;
		}
		else // не словил шарик
		{
			isDead = true;
			if (wait < timeDeath)
			{
				std::cout << wait << std::endl;
				wait += time;
			}
			else
			{
				isDead = false;
				wait = 0;
				std::cout << "SMEEEEERT" << std::endl;
				m_posX = windows_width / 2;
				m_posY = windows_height / 2;
			}
		}
	}

	if (m_posY < 0)
	{
		m_ySpeed *= -1;
		m_posY = 0;
	}
	if (m_posY > windows_height - pongBall_Radius * 2)
	{
		m_ySpeed *= -1;
		m_posY = windows_height - pongBall_Radius * 2;
	}
}