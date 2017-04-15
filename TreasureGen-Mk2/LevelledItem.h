#pragma once
#include "Item.h"

class LevelledItem : Item
{
public:
	int level;

	LevelledItem(int start, int end, string name, int level) : Item(start, end, name)
	{
		this->level = level;
	}
};