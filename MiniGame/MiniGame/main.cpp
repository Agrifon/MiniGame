#include "main.h"
#include "application.h"

int main(int argc, char* argv[])
{
	char mode;
	std::cin >> mode;

	Application application(mode);

	application.init();
	application.run();
	application.end();

	return 0;
}