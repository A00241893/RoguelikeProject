#ifndef UTILS_H
#define UTILS_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Player.h"

class Utils
{
public:

	static void gotoXY(short C, short R);
	static void clearScene();
	static void renderGUI(Player& p);
	static void printInventory(std::vector<Item>& inv);
};

#endif // UTILS_H