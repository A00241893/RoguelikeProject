#pragma once
#include <windows.h>
#include <iostream>
#include "Player.h"

class Utils
{
public:

	static void gotoXY(short C, short R);
	static void clearScene();
	static void renderMap(int lHeight, char* map[]);
	static void renderGUI(Player& p, int lHeight);
};