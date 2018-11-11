#include "Weapon.h"

Weapon::Weapon()
{
	damage = 0;
}

Weapon::Weapon(int x, int y, char s, std::string n, int d)
	: Item(x, y, s,n)
{
	damage = d;
}

void Weapon::setDamage(int d)
{
	damage = d;
}
int Weapon::getDamage() const
{
	return damage;
}

//void Weapon::useItem(Player& p)
//{
//	p.setDamage(damage);
//}