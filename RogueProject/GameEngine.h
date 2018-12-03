#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
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
	bool handleInput();
	bool inventoryInput();
	void useItemFromInventory();
	void battleSystem(Player& p, Enemy& e);

private:
	Map* gameMap;
	Player* p;
	Enemy* e;
	Item *itemPtr[5];
	bool invActive = false;
	bool lose = false;
};

#endif // GAMEENGINE_H