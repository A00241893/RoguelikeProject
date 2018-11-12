#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Player.h"
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"
#include "Utils.h"

class GameEngine
{
public:
	GameEngine();
	void init();
	void run();
	void renderGUI();
	void renderInventory();
	void handleCollisions();
	bool handleInput();
	bool invInput();
	void dropItem();
	void useItem();

private:
	Map* gameMap;
	Player* p;
	Item *itemPtr[5];
	static const int LEVELWIDTH = 20;
	static const int LEVELHEIGHT = 10;
	bool invActive = false;
	std::vector<Item> inventory;
};

#endif // GAMEENGINE_H