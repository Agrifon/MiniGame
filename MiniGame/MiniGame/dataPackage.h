#ifndef DATAPACKAGE_H
#define DATAPACKAGE_H

#include <string>

struct package
{
public:
	float m_pong_posX;
	float m_pong_posY;

	float m_player1_posX;
	float m_player1_posY;
	int m_player1_score;

	float m_player2_posX;
	float m_player2_posY;
	int m_player2_score;

	std::string structToString();
	void stringToStruct(std::string dataStr);
};
#endif