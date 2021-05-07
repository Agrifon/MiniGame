#include "main.h"
#include "application.h"

int main(int argc, char* argv[])
{
	Application application;

	application.init();
	application.run();
	application.end();

	return 0;
}