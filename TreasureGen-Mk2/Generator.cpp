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