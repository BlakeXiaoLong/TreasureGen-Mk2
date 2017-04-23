#pragma once
#include "Item.h"

class Armor : public Item
{
public:
	enum Type { armor, shield };
	Type type;
	int enb = 0;
	string enh = "";

	Armor()
	{
	}
	Armor(int start, int end, string name, Type type) : Item(start, end, name)
	{
		this->type = type;
	}
};