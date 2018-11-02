#ifndef CONTROLS_H
#define CONTROLS_H
#include "Utils.h"

class Controls
{
public:
	static bool handleInput(Player & p, std::vector<Item>& inv);
	static bool invInput(Player& p, Map& gameMap, std::vector<Item>& inv);
};

#endif // CONTROLS_H