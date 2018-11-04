#include "GameEngine.h"


void GameEngine::renderGUI(Player& p)
{
	/** prints the GUI under the map
	**/
	Utils::gotoXY(2, 12);
	std::cout << "Health: " << p.getHealth();
	Utils::gotoXY(2, 13);
	std::cout << "Armour: " << p.getArmour();
	Utils::gotoXY(2, 14);
	std::cout << "Damage: " << p.getDamage();

	Utils::printMsg(0, 18, "Press I to go to the Inventory");
}

void GameEngine::renderInventory(std::vector<Item>& inv)
{
	Utils::clearScene();
	std::cout << "Inventory:" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i < inv.size(); i++)		//prints out the vector of inventory items
	{
		std::cout << i << ": " << inv[i].getItemName() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}

bool GameEngine::handleInput(Player& p, std::vector<Item>& inv)
{
	char input = _getch();
	p.setNewPositionX(p.getPositionX());
	p.setNewPositionY(p.getPositionY());

	if (GetKeyState(VK_UP) & 0x8000)
	{
		p.setNewPositionY(p.getPositionY() - 1);
		return false;
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		p.setNewPositionY(p.getPositionY() + 1);
		return false;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		p.setNewPositionX(p.getPositionX() + 1);
		return false;
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		p.setNewPositionX(p.getPositionX() - 1);
		return false;
	}
	if (input == 'i' || input == 'I') //prints out inventory when I is pressed
	{
		GameEngine::renderInventory(inv);
		return true;
	}
}

bool GameEngine::invInput(Player& p, Map& gameMap, std::vector<Item>& inv)
{
	char input = _getch();
	while (true) {

		Utils::printMsg(0, 18, "Press 'G' to go back to game , 'D' to delete an item");
		std::cin >> input;
		if (input == 'g' || input == 'G') //if player presses g, exits the inventory and goes back to game
		{
			Utils::clearScene(); //removes inventory scene
			gameMap.printMap(); //prints map
			return true;	//disables inventory controls
		}
		if (input == 'd' || input == 'D' && inv.size() >= 0) //if player presses d to drop item.
		{
			int itemToDrop;
			Utils::printMsg(0, 18, "select the number you want to drop:");
			std::cin >> itemToDrop;
			if (itemToDrop >= 0 && itemToDrop <= inv.size())
			{
				//prints item symbol back onto map
				if (p.dropItem(inv[itemToDrop].getItemSymbol(), gameMap, p) == true)
				{
					//removes item from inventory
					inv.erase(inv.begin() + itemToDrop);
					GameEngine::renderInventory(inv);
				}
				else {
					GameEngine::renderInventory(inv);
				}
			}
			else {}
		}
	}
}


