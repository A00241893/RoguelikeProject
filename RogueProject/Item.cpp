#include "Item.h"

Item::Item()
{
	name = " ";
	itemSymbol = ' ';
}

Item::Item(char s, std::string n)
{
	name = n;
	itemSymbol = s;
}

void Item::setItemSymbol(char s)
{
	itemSymbol = s;
}
char Item::getItemSymbol()
{
	return itemSymbol;
}
void Item::setItemName(std::string n)
{
	name = n;
}
std::string Item::getItemName() const
{
	return name;
}