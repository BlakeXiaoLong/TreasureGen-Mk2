#include "Generator.h"
using namespace std;

int main()
{
	vector<Armor> armor;
	vector<Weapon> weapons;
	vector<vector<Item>> gems, staffs, rods, rings, wondrous;
	vector<vector<PricedItem>> art;
	vector<vector<LevelledItem>> wands, scrolls, potions;
	buildEverything(armor, weapons, art, gems, wands, scrolls, potions, staffs, rods, rings, wondrous);
}

stringstream coinGen(int num, int die, Coin = gp, int multiplier = 1)
{

}
stringstream gemGen(int grade, int num = 1)
{

}
stringstream artGen(int grade, int num = 1)
{

}
stringstream scrollGen(Grade grade, int num = 1)
{

}
stringstream wandGen(Grade grade, int num = 1)
{

}
stringstream potionGen(Grade grade, int num = 1)
{

}
stringstream armorGen(Grade grade, int num = 1)
{

}
stringstream weaponGen(Grade grade, int num = 1)
{

}
stringstream ringGen(Grade grade, int num = 1)
{

}
stringstream wondrousGen(Grade grade, int num = 1)
{

}
stringstream staffGen(Grade grade, int num = 1)
{

}
stringstream rodGen(Grade grade, int num = 1)
{

}