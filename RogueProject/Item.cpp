#include "Item.h"

Item::Item()
{
	name = " ";
	symbol = ' ';
}

Item::Item(char s, std::string n)
{
	name = n;
	symbol = s;
}

void Item::setItemSymbol(int s)
{
	symbol = s;
}
int Item::getItemSymbol()
{
	return symbol;
}
void Item::setItemName(std::string n)
{
	name = n;
}
std::string Item::getItemName()
{
	return name;
}