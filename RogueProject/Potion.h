#ifndef POTION_H
#define POTION_H
#include <string>
#include "Item.h"

class Potion : public Item
{
public:
	Potion();
	Potion(char symbol, std::string name);
	//void usePotion(Player& p);
};

#endif // POTION_H