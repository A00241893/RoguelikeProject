#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Player.h"

class Item
{
public:
	Item();
	Item(char itemSymbol, std::string name);
	void setItemSymbol(char s);
	char getItemSymbol();
	void setItemName(std::string n);
	std::string getItemName() const;

private:
	char itemSymbol;
	std::string name;
};

#endif // ITEM_H