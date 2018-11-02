#ifndef ARMOUR_H
#define ARMOUR_H
#include "Item.h"

class Armour : public Item
{
public:
	Armour();
	Armour(char symbol, std::string name, int armour);
	void setArmour(int a);
	int getArmour() const;
	//void useArmour(Player& p, int amount);

private:
	int armour;
};

#endif // ARMOUR_H