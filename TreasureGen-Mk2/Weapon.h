#pragma once
#include "Item.h"

class Weapon : Item
{
public:
	enum Type { melee, ranged };
	Type type;

	Weapon(int start, int end, string name, Type type) : Item(start, end, name)
	{
		this->type = type;
	}
};