#include "Potion.h"

Potion::Potion(){}

Potion::Potion(int x, int y, int newX, int newY, char s, std::string n, int health)
	: Item(x, y, newX, newY, s, n){}

void Potion::setHealth(int h)
{
	health = h;
}
int Potion::getHealth() const
{
	return health;
}

//void Potion::useItem(Player& p)
//{
//	p.setHealth(p.getHealth() + health);
//	if (p.getHealth() > 100)
//	{
//		p.setHealth(100);
//	}
//}
