#include "Generator.h"
using namespace std;

vector<Armor> armor;
vector<Weapon> weapons;
vector<vector<Item>> gems, staffs, rods, rings, wondrous;
vector<vector<PricedItem>> art;
vector<vector<LevelledItem>> wands, scrolls, potions;

int main()
{
	srand((unsigned int)time(NULL));
	buildEverything(armor, weapons, art, gems, wands, scrolls, potions, staffs, rods, rings, wondrous);

	return 0;
}

int roll(int num, int die, int multiplier)
{
	int result = 0;
	for (int i = 0; i < num; i++)
		result += rand() % die + 1;
	return result * multiplier;
}
template <class T> T select(vector<vector<T>> atlases, int grade)
{
	stringstream ss;
	int rollA = roll(1, 100);
	vector<T> atlas = atlases.at(grade - 1);
	for (int i = 0; i < atlas.size(); i++)
		if (rollA <= atlas.at(i).end)
			return atlas.at(i);
	return T();
}
string coinGen(int num, int die, Coin coin, int multiplier)
{
	stringstream ss;
	ss << roll(num, die, multiplier);
	switch (coin)
	{
	case cp: ss << " cp\n"; break;
	case sp: ss << " sp\n"; break;
	case gp: ss << " gp\n"; break;
	case pp: ss << " pp\n"; break;
	}
	return ss.str();
}
string gemGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		ss << select(gems, grade).name;
		switch (grade)
		{
		case LMi: ss << " (worth " << roll(2, 4) + 5 << " gp)\n"; break;
		case GMi: ss << " (worth " << roll(2, 4, 5) + 25 << " gp)\n"; break;
		case LMe: ss << " (worth " << roll(2, 4, 10) + 50 << " gp)\n"; break;
		case GMe: ss << " (worth " << roll(2, 4, 50) + 250 << " gp)\n"; break;
		case LMa: ss << " (worth " << roll(2, 4, 100) + 500 << " gp)\n"; break;
		case GMa: ss << " (worth " << roll(2, 4, 500) + 2500 << " gp)\n"; break;
		}
	}
	return ss.str();
}
string artGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		PricedItem o = select(art, grade);
		ss << o.name << " (worth " << o.cost << ")\n";
	}
	return ss.str();
}
string scrollGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		int rollA = roll(1, 100), rollB = roll(1, 100), level = 0;
		bool common = false, arcane = false;

		switch (grade)
		{
		case LMi:
			if (rollA <= 15) level = 0;
			else if (rollA <= 95) level = 1;
			else if (rollA <= 100) level = 2;
			break;
		case GMi:
			if (rollA <= 5) level = 0;
			else if (rollA <= 35) level = 1;
			else if (rollA <= 90) level = 2;
			else if (rollA <= 100) level = 3;
			break;
		case LMe:
			if (rollA <= 10) level = 2;
			else if (rollA <= 55) level = 3;
			else if (rollA <= 100) level = 4;
			break;
		case GMe:
			if (rollA <= 20) level = 3;
			else if (rollA <= 60) level = 4;
			else if (rollA <= 100) level = 5;
			break;
		case LMa:
			if (rollA <= 30) level = 4;
			else if (rollA <= 65) level = 5;
			else if (rollA <= 90) level = 6;
			else if (rollA <= 100) level = 7;
			break;
		case GMa:
			if (rollA <= 5) level = 6;
			else if (rollA <= 35) level = 7;
			else if (rollA <= 70) level = 8;
			else if (rollA < 100) level = 9;
			break;
		}
		if (rollB <= 45)
		{
			common = true;
			arcane = true;
		}
		else if (rollB <= 60)
		{
			common = false;
			arcane = true;
		}
		else if (rollB <= 90)
		{
			common = true;
			arcane = false;
		}
		else if (rollB <= 100)
		{
			common = false;
			arcane = false;
		}
		
		level = (level * 2) + (common ? 0 : 1) + (arcane ? 0 : 20);
		LevelledItem o = select(scrolls, level + 1);
		ss << o.name << " (level " << o.level << ")\n";
	}
	return ss.str();
}
string wandGen(Grade grade, int num)
{
	stringstream ss;
	return ss.str();
}
string potionGen(Grade grade, int num)
{
	stringstream ss;
	return ss.str();
}
string armorGen(Grade grade, int num)
{
	stringstream ss;
	return ss.str();
}
string weaponGen(Grade grade, int num)
{
	stringstream ss;
	return ss.str();
}
string ringGen(Grade grade, int num)
{
	stringstream ss;
	return ss.str();
}
string wondrousGen(Grade grade, int num)
{
	stringstream ss;
	return ss.str();
}
string staffGen(Grade grade, int num)
{
	stringstream ss;
	return ss.str();
}
string rodGen(Grade grade, int num)
{
	stringstream ss;
	return ss.str();
}