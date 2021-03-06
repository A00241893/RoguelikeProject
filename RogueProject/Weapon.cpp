#include "Weapon.h"

Weapon::Weapon()
{
	damage = 0;
}

Weapon::Weapon(char s, std::string n, int d)
	: Item(s,n)
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

void Weapon::useItem(Player& p) const
{
	p.setDamage(damage);
}