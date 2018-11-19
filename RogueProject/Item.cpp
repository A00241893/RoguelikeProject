#include "Item.h"

Item::Item()
{
	name = " ";
}

Item::Item(char symbol, std::string n)
{
	GameEntity::setSymbol(symbol);
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