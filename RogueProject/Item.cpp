#include "Item.h"

Item::Item()
{
	name = " ";
}

Item::Item(int x, int y, char symbol, std::string n)
	:GameEntity(x, y, symbol)
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

void Item::useItem(Player& p) const{}