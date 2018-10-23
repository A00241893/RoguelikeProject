#ifndef UTILS_H
#define UTILS_H
#include <windows.h>
#include <iostream>
#include "Player.h"

class Utils
{
public:

	static void gotoXY(short C, short R);
	static void clearScene();
	static void renderMap(int lHeight, int lWidth, char* m[]);
	static void renderGUI(Player& p);
};

#endif // UTILS_H