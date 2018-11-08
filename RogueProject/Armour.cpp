#include "Armour.h"

Armour::Armour()
{
	armour = 0;
}

Armour::Armour(int x, int y, int newX, int newY, char s, std::string n, int a)
	: Item(x, y, newX, newY, s, n)
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

//void Armour::useItem(Player& p)
//{
//	p.setDamage(armour);
//}