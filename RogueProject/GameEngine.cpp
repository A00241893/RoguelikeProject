#include "GameEngine.h"

GameEngine::GameEngine(){}

void GameEngine::init()
{
	itemPtr[0] = new Potion('H', "Health", 20);
	itemPtr[1] = new Weapon('S', "Sword", 5);
	itemPtr[2] = new Weapon('M', "Mace", 10);
	itemPtr[3] = new Armour('L', "Leather", 5);
	itemPtr[4] = new Armour('I', "Iron", 10);

	gameMap = new Map();
	gameMap->loadMap("Map.txt");
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
			p->addToInventory(itemPtr[i]->getItemName()); //adds item to the inventory

			// Remove it from the map
			gameMap->setXY(p->getNewPositionY(), p->getNewPositionX(), '.');
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
		p->renderInventory();
		return true;
	}
}

void GameEngine::useItem()
{
	int itemToUse;
	Utils::printMsg(0, 18, "select the number you want to use:");
	std::cin >> itemToUse;
	if (itemToUse >= 0 && itemToUse <= p->inventory.size()) //if valid number is entered and something is in the inventory
	{
		for (int i = 0; i < 5; i++)
		{
			if (p->inventory[itemToUse] == itemPtr[i]->getItemName()) //finds what item it is
			{
				itemPtr[i]->useItem(*p);
			}
			else {}
		}
		
		//removes item from inventory
		p->inventory.erase(p->inventory.begin() + itemToUse);
		p->renderInventory();
	}
	else {
		Utils::printMsg(0, 17, "enter valid input!!");
	}
}

bool GameEngine::invInput()
{
	char input = _getch();
	while (true) {

		Utils::printMsg(0, 18, "Press 'G' to go back to game , 'D' to drop an item , 'U' to use an item");
		std::cin >> input;
		if (input == 'g' || input == 'G') //if player presses g, exits the inventory and goes back to game
		{
			Utils::clearScene(); //removes inventory scene
			gameMap->printMap(); //prints map
			GameEngine::renderGUI(); // prints GUI
			return true;	//disables inventory controls
		}
		if (input == 'd' || input == 'D' && p->inventory.size() >= 0) //if player presses d to drop item.
		{
			p->removeFromInventory(*gameMap, *p);
		}
		if (input == 'u' || input == 'U' && p->inventory.size() >= 0) //if player presses u to use item.
		{
			GameEngine::useItem();
		}
	}
}
