#include "Armour.h"

Armour::Armour()
{
	armour = 0;
}

Armour::Armour(char s, std::string n, int a)
	: Item(s, n)
{
	armour = a;
}

void Armour::setArmour(int a)
{
	armour = a;
}
int Armour::getArmour() const
{
	return armour;
}

//void Armour::useArmour(Player& p, int amount)
//{
//	p.setArmour(amount);
//}