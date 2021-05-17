#include "main.h"
#include "AIServer.h"

int main(int argc, char* argv)
{
	AI_server* server = new AI_server_boost_asio;

	server->accept();

	return 0;
}