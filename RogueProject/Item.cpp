#include "Item.h"

Item::Item()
{
	name = " ";
}

Item::Item(char symbol, std::string n)
	:GameEntity(symbol)
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