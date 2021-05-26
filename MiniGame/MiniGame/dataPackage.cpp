#include "dataPackage.h"

std::string package::structToString()
{
	std::string pongString(std::to_string(m_pong_posX) + '|' + std::to_string(m_pong_posY) + '|');
	std::string player1String(std::to_string(m_player1_posX) + '|' + std::to_string(m_player1_posY) + '|' + std::to_string(m_player1_score) + '|');
	std::string player2String(std::to_string(m_player2_posX) + '|' + std::to_string(m_player2_posY) + '|' + std::to_string(m_player2_score) + '|');
	
	return std::string(pongString + player1String + player2String);
}

void package::stringToStruct(std::string dataStr)
{
	std::string temp;

	temp.insert(0, dataStr, 0, dataStr.find_first_of('|')); //вставляет в temp всё до попавшегося |
	dataStr.erase(0, dataStr.find_first_of('|') + 1); //удаляет с переданной строки первый передаваемый элемент
	m_pong_posX = atof(temp.c_str()); // передает в структуру переменную
	temp.clear(); // чистит temp

	temp.insert(0, dataStr, 0, dataStr.find_first_of('|'));
	dataStr.erase(0, dataStr.find_first_of('|') + 1);
	m_pong_posY = atof(temp.c_str());
	temp.clear();

	temp.insert(0, dataStr, 0, dataStr.find_first_of('|'));
	dataStr.erase(0, dataStr.find_first_of('|') + 1);
	m_player1_posX = atof(temp.c_str());
	temp.clear();

	temp.insert(0, dataStr, 0, dataStr.find_first_of('|'));
	dataStr.erase(0, dataStr.find_first_of('|') + 1);
	m_player1_posY = atof(temp.c_str());
	temp.clear();

	temp.insert(0, dataStr, 0, dataStr.find_first_of('|'));
	dataStr.erase(0, dataStr.find_first_of('|') + 1);
	m_player1_score = atof(temp.c_str());
	temp.clear();

	temp.insert(0, dataStr, 0, dataStr.find_first_of('|'));
	dataStr.erase(0, dataStr.find_first_of('|') + 1);
	m_player2_posX = atof(temp.c_str());
	temp.clear();

	temp.insert(0, dataStr, 0, dataStr.find_first_of('|'));
	dataStr.erase(0, dataStr.find_first_of('|') + 1);
	m_player2_posY = atof(temp.c_str());
	temp.clear();

	temp.insert(0, dataStr, 0, dataStr.find_first_of('|'));
	dataStr.erase(0, dataStr.find_first_of('|') + 1);
	m_player2_score = atof(temp.c_str());
	temp.clear();
}