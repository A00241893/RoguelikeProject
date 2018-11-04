#ifndef POTION_H
#define POTION_H
#include <string>
#include "Item.h"

class Potion : public Item
{
public:
	Potion();
	Potion(char symbol, std::string name);
};

#endif // POTION_H