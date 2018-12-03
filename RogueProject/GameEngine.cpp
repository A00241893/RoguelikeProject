#include "GameEngine.h"

GameEngine::GameEngine(){}

void GameEngine::init()
{
	itemPtr[0] = new Potion('H', "Health", 20);
	itemPtr[1] = new Weapon('S', "Sword", 5);
	itemPtr[2] = new Weapon('M', "Mace", 10);
	itemPtr[3] = new Armour('L', "Leather", 15);
	itemPtr[4] = new Armour('I', "Iron", 30);

	gameMap = new Map();
	gameMap->loadMap("Map.txt");
	gameMap->printMap();

	p = new Player(5,5,5,5, 'P', 50, 0, 0);
	e = new Enemy(14,7,14,7, 'E',60,3,"Goblin");
	e1 = new Enemy(10, 11, 10, 11, 'E', 60, 3, "Goblin");

	GameEngine::renderGUI(); //prints GUI
}

void GameEngine::run()
{
	e->renderActor(*e);
	e1->renderActor(*e1);

	while (lose != true)
	{
		if (invActive == false) //inventory screen inactive
		{
			p->renderActor(*p); // Render the scene
			if(e->enemyState(*p,*gameMap,*e) == true) // enemy 1
			{
				battleSystem(*p, *e);
			}
			if (e1->enemyState(*p, *gameMap, *e1) == true) // enemy 2
			{
				battleSystem(*p, *e1);
			}

			if (GameEngine::handleInput() == true) // Handles the input
			{
				invActive = true; // activates inventory
			}
			p->handleCollisions(*gameMap, *p); // Handle collisions
		}
		else if (invActive == true)
		{
			if (GameEngine::inventoryInput() == true) //inventory controls
			{
				invActive = false; // activates game controls
			}
			e->renderActor(*e); // renders enemy after return from inventory
			e1->renderActor(*e1);
		}
	}
	Utils::clearScene();
	Utils::printMsg(0, 5, "You Died");
	system("pause");
}

void GameEngine::renderGUI()
{
	/** prints the GUI under the map
	**/
	Utils::gotoXY(2, 14);
	std::cout << "Health: " << p->getHealth();
	Utils::gotoXY(2, 15);
	std::cout << "Armour: " << p->getArmour();
	Utils::gotoXY(2, 16);
	std::cout << "Damage: " << p->getDamage();

	Utils::printMsg(0, 18, "Press I to go to the Inventory");
}

void GameEngine::battleSystem(Player& p, Enemy& e)
{
	bool enemyAlive = true;
	e.setHealth(e.getHealth() - p.getDamage()); //damages enemy health
	if (e.getHealth() <= 0)
	{
		enemyAlive = false;
		delete &e;	//when enemy health is 0 deletes enemy
	}

	if (enemyAlive != false) //while enemy is alive
	{
		if (p.getArmour() > 0) //enemy damages player armour first.
		{
			p.setArmour(p.getArmour() - e.getDamage());
			if (p.getArmour() < 0) //sets armour to 0 if it goes below 0
			{
				p.setArmour(0);
			}
		}else
		{
			p.setHealth(p.getHealth() - e.getDamage());
			if (p.getHealth() <= 0)
			{
				lose = true; //stops game when player dies.
			}
		}
	}
	GameEngine::renderGUI();
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

void GameEngine::useItemFromInventory()
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

bool GameEngine::inventoryInput()
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
			GameEngine::useItemFromInventory();
		}
	}
}
