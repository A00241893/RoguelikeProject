#include "Item.h"

Item::Item()
{
	name = " ";
}

Item::Item(int x, int y, int newX, int newY, char symbol, std::string n)
	:GameEntity(x, y, newX, newY, symbol)
{
	name = n;
}

void Item::setItemName(std::string n)
{
	name = n;
}
std::string Item::getItemName() const
{
	return name;
}

//void Item::useItem(Player& p) {}