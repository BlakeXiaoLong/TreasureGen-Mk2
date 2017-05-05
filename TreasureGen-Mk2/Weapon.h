#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	enum Type { melee, ranged };
	Type type;
	int enb = 0;
	string enh = "";
	bool specific = false;

	Weapon()
	{
	}
	Weapon(int start, int end, string name, Type type) : Item(start, end, name)
	{
		this->type = type;
	}
};