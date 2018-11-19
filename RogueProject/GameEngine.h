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
	void handleCollisions();
	bool handleInput();
	bool invInput();
	void useItem();

private:
	Map* gameMap;
	Player* p;
	Item *itemPtr[5];
	bool invActive = false;
};

#endif // GAMEENGINE_H