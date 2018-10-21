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

void Item::setItemSymbol(int s)
{
	itemSymbol = s;
}
int Item::getItemSymbol()
{
	return itemSymbol;
}
void Item::setItemName(std::string n)
{
	name = n;
}
std::string Item::getItemName()
{
	return name;
}