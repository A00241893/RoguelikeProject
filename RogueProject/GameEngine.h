#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Player.h"
#include "Utils.h"

class GameEngine
{
public:

	void renderGUI(Player& p);
	void renderInventory(std::vector<Item>& inv);
	bool handleInput(Player & p, std::vector<Item>& inv);
	bool invInput(Player& p, Map& gameMap, std::vector<Item>& inv);
};

#endif // GAMEENGINE_H