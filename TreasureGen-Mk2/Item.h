#pragma once
#include <string>
using namespace std;

class Item
{
public:
	int start, end;
	string name;

	Item(int start, int end, string name)
	{
		this->name = name;
		this->start = start;
		this->end = end;
	}
};