#pragma once
#include "Item.h"

class Armor : Item
{
public:
	enum Type { armor, shield };
	Type type;

	Armor(int start, int end, string name, Type type) : Item(start, end, name)
	{
		this->type = type;
	}
};