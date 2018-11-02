#include "Controls.h"

bool Controls::handleInput(Player& p, std::vector<Item>& inv)
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
		Utils::printInventory(inv);
		return true;
	}
}

bool Controls::invInput(Player& p, Map& gameMap, std::vector<Item>& inv)
{
	char input = _getch();
	while (true) {

		Utils::gotoXY(0, 18);
		std::cout << "Press 'G' to go back to game or 'D' to delete an item" << std::endl;
		std::cin >> input;
		if (input == 'g' || input == 'G')
		{
			Utils::clearScene();
			gameMap.printMap();

			return true;	//disables inventory controls
		}
		if (input == 'd' || input == 'D' && inv.size() >= 0)
		{
			int input;
			Utils::gotoXY(0, 18);
			std::cout << "select the number you want to delete:                       " << std::endl;
			std::cin >> input;
			if (input >= 0 && input <= inv.size())
			{
				//prints first letter of items name back onto map
				if (p.dropItem(inv[input].getItemSymbol(), gameMap, p) == true)
				{
					//removes item from inventory
					inv.erase(inv.begin() + input);
					Utils::printInventory(inv);
				}
				else
				{
					Utils::printInventory(inv);
				}
			}
			else {}
		}
	}
}