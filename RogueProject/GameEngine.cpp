#include "GameEngine.h"

GameEngine::GameEngine(){}

void GameEngine::init()
{
	char map[LEVELHEIGHT][LEVELWIDTH + 1] =
	{ "aaaaaaaaaaaaaaaaaaaa",
		"a                  a",
		"a                  a",
		"a                  a",
		"a                  a",
		"a                  a",
		"a                  a",
		"a                  a",
		"a                  a",
		"aaaaaaaaaaaaaaaaaaaa"
	};

	itemPtr[0] = new Potion(2, 16, 'h', "Health", 20);
	itemPtr[1] = new Weapon(3, 8, 's', "Sword", 5);
	itemPtr[2] = new Weapon(7, 16, 'm', "Mace", 10);
	itemPtr[3] = new Armour(8, 5, 'l', "Leather", 5);
	itemPtr[4] = new Armour(6, 13, 'i', "Iron", 10);

	gameMap = new Map();
	gameMap->initMap(&map[0][0], LEVELWIDTH + 1, LEVELHEIGHT);

	for (int i = 0; i < 5; i++) //adds items to map
	{
		gameMap->setXY(itemPtr[i]->getPositionX(), itemPtr[i]->getPositionY(), itemPtr[i]->getSymbol());
	}

	gameMap->printMap();

	p = new Player(5,5,5,5, 'P', 50, 0, 0);

	GameEngine::renderGUI(); //prints GUI
}

void GameEngine::run()
{
	while (true)
	{
		if (invActive == false) //inventory screen inactive
		{
			p->renderPlayer(*p); // Render the scene

			if (GameEngine::handleInput() == true) // Handles the input
			{
				invActive = true; // activates inventory
			}
			
			GameEngine::handleCollisions(); // Handle collisions
		}
		if (invActive == true)
		{
			if (GameEngine::invInput() == true) //inventory controls
			{
				invActive = false; // activates game controls
			}
		}
	}
}

void GameEngine::renderGUI()
{
	/** prints the GUI under the map
	**/
	Utils::gotoXY(2, 12);
	std::cout << "Health: " << p->getHealth();
	Utils::gotoXY(2, 13);
	std::cout << "Armour: " << p->getArmour();
	Utils::gotoXY(2, 14);
	std::cout << "Damage: " << p->getDamage();

	Utils::printMsg(0, 18, "Press I to go to the Inventory");
}

void GameEngine::renderInventory()
{
	Utils::clearScene();
	std::cout << "Inventory:" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i < inventory.size(); i++)		//prints out the vector of inventory items
	{
		std::cout << i << ": " << inventory[i].getItemName() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}

void GameEngine::handleCollisions()
{
	// Check the location that the player wants to move to on the map
	char nextLocation = gameMap->getXY(p->getNewPositionY(), p->getNewPositionX());

	// If the nextLocation is a border....
	if (nextLocation == 'a')
	{
		// ....then don't move i.e. set the new position back to the old position
		p->setNewPositionX(p->getPositionX());
		p->setNewPositionY(p->getPositionY());
	}
	for (int i = 0; i < 5; i++)
	{
		if (nextLocation == itemPtr[i]->getSymbol()) //if the player collides with an item.
		{
			inventory.push_back(*itemPtr[i]); //adds item to the inventory

											  // Remove it from the map
			gameMap->setXY(p->getNewPositionY(), p->getNewPositionX(), ' ');
		}
	}
}

bool GameEngine::handleInput()
{
	char input = _getch();
	p->setNewPositionX(p->getPositionX());
	p->setNewPositionY(p->getPositionY());

	if (GetKeyState(VK_UP) & 0x8000)
	{
		p->setNewPositionY(p->getPositionY() - 1);
		return false;
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		p->setNewPositionY(p->getPositionY() + 1);
		return false;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		p->setNewPositionX(p->getPositionX() + 1);
		return false;
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		p->setNewPositionX(p->getPositionX() - 1);
		return false;
	}
	if (input == 'i' || input == 'I') //prints out inventory when I is pressed
	{
		GameEngine::renderInventory();
		return true;
	}
}

bool GameEngine::invInput()
{
	char input = _getch();
	while (true) {

		Utils::printMsg(0, 18, "Press 'G' to go back to game , 'D' to delete an item");
		std::cin >> input;
		if (input == 'g' || input == 'G') //if player presses g, exits the inventory and goes back to game
		{
			Utils::clearScene(); //removes inventory scene
			gameMap->printMap(); //prints map
			GameEngine::renderGUI(); // prints GUI
			return true;	//disables inventory controls
		}
		if (input == 'd' || input == 'D' && inventory.size() >= 0) //if player presses d to drop item.
		{
			int itemToDrop;
			Utils::printMsg(0, 18, "select the number you want to drop:");
			std::cin >> itemToDrop;
			if (itemToDrop >= 0 && itemToDrop <= inventory.size()) //if valid no if entered and something is in the inventory
			{
				//prints item symbol back onto map
				if (p->dropItem(inventory[itemToDrop].getSymbol(), *gameMap, *p) == true)
				{
					//removes item from inventory
					inventory.erase(inventory.begin() + itemToDrop);
					GameEngine::renderInventory();
				}
				else {
					GameEngine::renderInventory();
					Utils::printMsg(0, 17, "no space to drop item!!");
				}
			}
			else {
				Utils::printMsg(0, 17, "enter valid input!!");
			}
		}
	}
}
