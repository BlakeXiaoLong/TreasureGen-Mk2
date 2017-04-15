#pragma once
#include "Item.h"

class PricedItem : Item
{
public:
	int cost;

	PricedItem(int start, int end, string name, int cost) : Item(start, end, name)
	{
		this->cost = cost;
	}
};