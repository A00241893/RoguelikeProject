#include <windows.h>
#include <iostream>
#include "GameEngine.h"

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	GameEngine gameEng;

	gameEng.init();
	gameEng.run();

	return 0;
}