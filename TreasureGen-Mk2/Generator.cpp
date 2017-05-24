#include "Generator.h"
using namespace std;

vector<Armor> armor;
vector<Weapon> weapons;
vector<vector<Item>> gems, staffs, rods, rings, wondrous, effects, enchantments, specifics;
vector<vector<PricedItem>> art;
vector<vector<LevelledItem>> wands, scrolls, potions;

int main()
{
	srand((unsigned int)time(NULL));
	buildEverything(armor, weapons, art, gems, wands, scrolls, potions, staffs, rods, rings, wondrous, effects, enchantments, specifics);
	generate(setup());
}

void cls()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
int setup()
{
	int npcVal[20] = { 260, 390, 780, 1650, 2400, 3450, 4650, 6000, 7800, 10050, 12750, 16350, 21000, 27000, 34800, 45000, 58500, 75000, 96000, 123000 };
	int crVal[20]  = { 400, 800, 1200, 1700, 2300, 3000, 3900, 5000, 6400, 8200, 10500, 13500, 17500, 22000, 29000, 38000, 48000, 62000, 79000, 100000 };
	int CR = 0, modifier = 0, value = 0;

	do
	{
		cout << "What CR was the encounter?\n";
		cin >> CR;
		cls();
		if (CR < 1 || CR > 20)
			cout << "Invalid response. Please enter an integer between 1 and 20\n\n";
	} while (CR < 1 || CR > 20);

	do
	{
		cout << "What level of trasure do you want this encounter to generate?\n";
		cout << "1. Incidental (50%)\n";
		cout << "2. Normal (100%)\n";
		cout << "3. Double (200%)\n";
		cout << "4. Triple (300%)\n";
		cout << "5. NPC Treasure\n";
		cin >> modifier;
		cls();
		if (modifier < 1 || modifier > 5)
			cout << "Invalid response. Please enter an integer between 1 and 5\n\n";
	} while (modifier < 1 || modifier > 5);

	if (modifier == 5)
	{
		int level = 0, n = 0;
		cout << "How many NPCs were there?";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			do
			{
				cout << "What level was the NPC?";
				cin >> level;
				cls();
				if (level < 1 || level > 20)
					cout << "Invalid response. Please enter a number between 1 and 20\n\n";
			} while (level < 1 || level > 20);
			value += npcVal[level - 1];
		}
	}
	else value = crVal[CR - 1] * modifier;
	return value;
}
void generate(int value)
{
	int type = 0;
	do
	{
		cout << "What type of treasure would you like to generate?\n";
		cout << "1. Coins\n";
		cout << "\tTreasure of this type consists entirely of coins\n";
		cout << "\tCarried By: Aberration, Animal, Dragon, Humanoid, Magical Beast, Monstrous Humanoid, Ooze, Outsider, Plant, Undead, Vermin\n";
		cout << "2. Coins and Gems\n";
		cout << "\tThis type also includes gemstones, some of which can be quite valuable\n";
		cout << "\tCarried By: Aberration, Animal, Construct, Dragon, Fey, Humanoid, Magical Beast, Monstrous Humanoid, Ooze, Outsider, Plant, Undead, Vermin\n";
		cout << "3. Art Objects\n";
		cout << "\tThese items are valuable for their beauty and craftsmanship\n\t and are made with precious metals, gems, and other fine materials\n";
		cout << "\tCarried By: Construct, Dragon, Fey, Monstrous Humanoid, Outsider\n";
		cout << "4. Coins and Small Objects\n";
		cout << "\tCoins and small magic items, such as potions, rings, scrolls, and wands\n";
		cout << "\tCarried By: Aberration, Animal, Fey, Humanoid, Magical Beast, Monstrous Humanoid, Ooze, Outsider, Plant, Undead, Vermin\n";
		cout << "5. Armor and Weapons\n";
		cout << "\tSolely Weapons and Armor\n";
		cout << "\tCarried By: Aberration, Animal, Construct, Humanoid, Magical Beast, Monstrous Humanoid, Outsider, Plant, Undead\n";
		cout << "6. Combatant Gear\n";
		cout << "\tArmor, coins, potions, weapons, and wondrous items\n";
		cout << "\tCarried By: Aberration, Construct, Humanoid, Undead\n";
		cout << "7. Spellcaster Gear\n";
		cout << "\tCoins, potions, scrolls, staves, wands, and other wondrous items\n";
		cout << "\tCarried By: Aberration, Fey, Humanoid, Outsider, Undead\n";
		cout << "8. Lair Treasure\n";
		cout << "\tA large number of magic items, coins, and other valuables\n";
		cout << "\tCarried By: Aberration, Construct, Dragon, Humanoid, Monstrous Humanoid, Outsider\n";
		cout << "9. Treasure Hoard\n";
		cout << "\tThis can contain virtually any type of item\n";
		cout << "\tCarried By: Dragon, Outsider\n";
		cin >> type;
		if (type < 1 || type > 9)
			cout << "Invalid response. Please enter an integer between 1 and 9\n\n";
	} while (type < 1 || type > 9);
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
		if (rollB <= 45) { common = true; arcane = true; }
		else if (rollB <= 60) { common = false; arcane = true; }
		else if (rollB <= 90) { common = true; arcane = false; }
		else if (rollB <= 100) { common = false; arcane = false; }

		LevelledItem o = select(scrolls, (level * 2) + (common ? 0 : 1) + (arcane ? 0 : 20) + 1);
		ss << o.name << " (level " << o.level << ")\n";
	}
	return ss.str();
}
string wandGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		int rollA = roll(1, 100), rollB = roll(1, 100), level = 0;
		bool common = false;

		switch (grade)
		{
		case LMi:
			if (rollA <= 40) level = 0;
			else if (rollA <= 100) level = 1;
			break;
		case GMi:
			if (rollA <= 80) level = 1;
			else if (rollA <= 100) level = 2;
			break;
		case LMe:
			if (rollA <= 75) level = 2;
			else if (rollA <= 100) level = 3;
			break;
		case GMe:
			if (rollA <= 20) level = 2;
			else if (rollA <= 80) level = 3;
			else if (rollA <= 100) level = 4;
			break;
		case LMa:
			if (rollA <= 60) level = 3;
			else if (rollA <= 100) level = 4;
			break;
		case GMa:
			if (rollA <= 30) level = 3;
			else if (rollA <= 100) level = 4;
			break;
		}
		if (rollB <= 70) common = true;
		else if (rollB <= 100) common = false;

		LevelledItem o = select(wands, (level * 2) + (common ? 0 : 1) + 1);
		ss << o.name << " (level " << o.level << ")\n";
	}
	return ss.str();
}
string potionGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		int rollA = roll(1, 100), rollB = roll(1, 100), level = 0;
		bool common = false;

		switch (grade)
		{
		case LMi:
			if (rollA <= 40) level = 0;
			else if (rollA <= 100) level = 1;
			break;
		case GMi:
			if (rollA <= 10) level = 0;
			else if (rollA <= 60) level = 1;
			else if (rollA <= 100) level = 2;
			break;
		case LMe:
			if (rollA <= 25) level = 1;
			else if (rollA <= 85) level = 2;
			else if (rollA <= 100) level = 3;
			break;
		case GMe:
			if (rollA <= 10) level = 1;
			else if (rollA <= 50) level = 2;
			else if (rollA <= 100) level = 3;
			break;
		case LMa:
			if (rollA <= 35) level = 2;
			else if (rollA <= 100) level = 3;
			break;
		case GMa:
			if (rollA <= 10) level = 2;
			else if (rollA <= 100) level = 3;
			break;
		}
		if (rollB <= 75)common = true;
		else if (rollB <= 100 && level != 0) common = false;

		LevelledItem o = select(potions, (level * 2) + (common ? 0 : 1) + 1);
		ss << o.name << " (level " << o.level << ")\n";
	}
	return ss.str();
}
string armorGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		Armor o;
		int rollA = roll(1, 100), rollB = roll(1, 100);
		for (int j = 0; j < armor.size(); j++)
			if (rollA <= armor.at(j).end)
			{
				o.name = armor.at(j).name;
				o.type = armor.at(j).type;
				break;
			}
		if (o.name == "") ss << armorGen(grade, 1);
		else
		{
			switch (grade)
			{
			case mwk:
				o.name = "Masterwork " + o.name;
				break;
			case LMi:
				if (rollB <= 80) o.enb = 1;
				else if (rollB <= 90) { o.specific = true; o.name = select(specifics, LMi).name; } // specific armor
				else { o.specific = true; o.name = select(specifics, LMi + 6).name; } // specific shield
				break;
			case GMi:
				if (rollB <= 26) o.enb = 1;
				else if (rollB <= 53) o.enb = 2;
				else if (rollB <= 80) { o.enb = 1; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 90) { o.specific = true; o.name = select(specifics, GMi).name; } // specific armor
				else { o.specific = true; o.name = select(specifics, GMi + 6).name; } // specific shield
				break;
			case LMe:
				if (rollB <= 10) o.enb = 1;
				else if (rollB <= 20) o.enb = 2;
				else if (rollB <= 32) o.enb = 3;
				else if (rollB <= 44) { o.enb = 1; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 56) { o.enb = 1; for (int j = 0; j < 2; j++) { o.enh += select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; } }
				else if (rollB <= 68) { o.enb = 1; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; }
				else if (rollB <= 80) { o.enb = 2; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 90) { o.specific = true; o.name = select(specifics, LMe).name; } // specific armor
				else { o.specific = true; o.name = select(specifics, LMe + 6).name; } // specific shield
				break;
			case GMe:
				if (rollB <= 10) o.enb = 2;
				else if (rollB <= 22) o.enb = 3;
				else if (rollB <= 32) { o.enb = 1; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; }
				else if (rollB <= 44) { o.enb = 1; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; }
				else if (rollB <= 56) { o.enb = 2; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 68) { o.enb = 2; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; }
				else if (rollB <= 80) { o.enb = 3; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 90) { o.specific = true; o.name = select(specifics, GMe).name; } // specific armor
				else { o.specific = true; o.name = select(specifics, GMe + 6).name; } // specific shield
				break;
			case LMa:
				if (rollB <= 10) o.enb = 3;
				else if (rollB <= 22) o.enb = 4;
				else if (rollB <= 32) { o.enb = 1; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; }
				else if (rollB <= 44) { o.enb = 1; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 3).name + " "; }
				else if (rollB <= 56) { o.enb = 2; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; }
				else if (rollB <= 68) { o.enb = 3; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 80) { o.enb = 4; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 90) { o.specific = true; o.name = select(specifics, LMa).name; } // specific armor
				else { o.specific = true; o.name = select(specifics, LMa + 6).name; } // specific shield
				break;
			case GMa:
				if (rollB <= 10) o.enb = 4;
				else if (rollB <= 20) o.enb = 5;
				else if (rollB <= 30) { o.enb = 4; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 38) { o.enb = 4; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; }
				else if (rollB <= 46) { o.enb = 4; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 3).name + " "; }
				else if (rollB <= 51) { o.enb = 4; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 4).name + " "; }
				else if (rollB <= 59) { o.enb = 5; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 1).name + " "; }
				else if (rollB <= 67) { o.enb = 5; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; }
				else if (rollB <= 71) { o.enb = 5; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 3).name + " "; }
				else if (rollB <= 74) { o.enb = 5; for (int j = 0; j < 2; j++) { o.enh += select(enchantments, (o.type == Armor::shield ? 5 : 0) + 2).name + " "; } }
				else if (rollB <= 77) { o.enb = 5; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 4).name + " "; }
				else if (rollB <= 80) { o.enb = 5; o.enh = select(enchantments, (o.type == Armor::shield ? 5 : 0) + 5).name + " "; }
				else if (rollB <= 90) { o.specific = true; o.name = select(specifics, GMa).name; } // specific armor
				else { o.specific = true; o.name = select(specifics, GMa + 6).name; } // specific shield
				break;
			}
			if (o.specific) ss << o.name << endl;
			else if (o.enh == " ") ss << armorGen(grade, 1);
			else { if (o.enb) ss << "+" << o.enb << " "; ss << o.enh << o.name << endl; }
		}
	}
	return ss.str();
}
string weaponGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		Weapon o;
		int rollA = roll(1, 100), rollB = roll(1, 100);
		for (int j = 0; j < weapons.size(); j++) if (rollA <= weapons.at(j).end) { o.name = weapons.at(j).name; o.type = weapons.at(j).type; break; }
		if (o.name == "")
			ss << weaponGen(grade, 1);
		else
		{
			switch(grade)
			{
			case mwk:
				o.name = "Masterwork " + o.name;
				break;
			case LMi:
				if (rollB <= 80) o.enb = 1;
				else { o.specific = true; o.name = select(specifics, LMi + 12).name; }
				break;
			case GMi:
				if (rollB <= 26) o.enb = 1;
				else if (rollB <= 53) o.enb = 2;
				else if (rollB <= 80) { o.enb = 1, o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else { o.specific = true; o.name = select(specifics, GMi + 12).name; }
				break;
			case LMe:
				if (rollB <= 10) o.enb = 1;
				else if (rollB <= 20) o.enb = 2;
				else if (rollB <= 32) o.enb = 3;
				else if (rollB <= 44) { o.enb = 1, o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else if (rollB <= 56) { o.enb = 1; for (int j = 0; j < 2; j++) { o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; } }
				else if (rollB < 68) { o.enb = 1; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 1).name + " "; }
				else if (rollB <= 80) { o.enb = 2; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else { o.specific = true; o.name = select(specifics, LMe + 12).name; }
				break;
			case GMe:
				if (rollB <= 10) o.enb = 2;
				else if (rollB <= 22) o.enb = 3;
				else if (rollB <= 32) { o.enb = 1; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else if (rollB <= 44) { o.enb = 1; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 1).name + " "; }
				else if (rollB <= 56) { o.enb = 2; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else if (rollB <= 68) { o.enb = 2; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 1).name + " "; }
				else if (rollB <= 80) { o.enb = 3; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else { o.specific = true; o.name = select(specifics, GMe + 12).name; }
				break;
			case LMa:
				if (rollB <= 10) o.enb = 3;
				else if (rollB <= 22) o.enb = 4;
				else if (rollB <= 32) { o.enb = 1; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 1).name + " "; }
				else if (rollB <= 44) { o.enb = 1; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 2).name + " "; }
				else if (rollB <= 56) { o.enb = 2; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 1).name + " "; }
				else if (rollB <= 68) { o.enb = 3; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else if (rollB <= 80) { o.enb = 4; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else { o.specific = true; o.name = select(specifics, LMa + 12).name; }
				break;
			case GMa:
				if (rollB <= 10) o.enb = 4;
				else if (rollB <= 20) o.enb = 5;
				else if (rollB <= 30) { o.enb = 4; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else if (rollB <= 38) { o.enb = 4; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 1).name + " "; }
				else if (rollB <= 46) { o.enb = 4; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 2).name + " "; }
				else if (rollB <= 51) { o.enb = 4; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 3).name + " "; }
				else if (rollB <= 59) { o.enb = 5; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else if (rollB <= 67) { o.enb = 5; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 1).name + " "; }
				else if (rollB <= 71) { o.enb = 5; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 2).name + " "; }
				else if (rollB <= 74) { o.enb = 5; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 3).name + " "; }
				else if (rollB <= 77) { o.enb = 5; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 3).name + " "; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10)).name + " "; }
				else if (rollB <= 80) { o.enb = 5; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 2).name + " "; o.enh = select(enchantments, (o.type == Weapon::ranged ? 15 : 10) + 1).name + " "; }
				else { o.specific = true; o.name = select(specifics, GMa + 12).name; }
				break;
			}
			if (o.specific) ss << o.name << endl;
			else if (o.enh == " ") ss << weaponGen(grade, 1);
			else { if (o.enb) ss << "+" << o.enb << " "; ss << o.enh << o.name << endl; }
		}
	}
	return ss.str();
}
string ringGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		Item o = select(rings, grade);
		ss << o.name + "\n";
	}
	return ss.str();
}
string wondrousGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		int type, rollA = roll(1, 100);
		if (rollA <= 6) type = 0;
		else if (rollA <= 12) type = 1;
		else if (rollA <= 17) type = 2;
		else if (rollA <= 22) type = 3;
		else if (rollA <= 28) type = 4;
		else if (rollA <= 34) type = 5;
		else if (rollA <= 41) type = 6;
		else if (rollA <= 47) type = 7;
		else if (rollA <= 54) type = 8;
		else if (rollA <= 61) type = 9;
		else if (rollA <= 67) type = 10;
		else if (rollA <= 100) type = 11;

		Item o = select(wondrous, 6 * type + grade);
		ss << o.name << "\n";
	}
	return ss.str();
}
string staffGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		Item o = select(staffs, grade);
		ss << o.name << "\n";
	}
	return ss.str();
}
string rodGen(Grade grade, int num)
{
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		int rollA = roll(1, 100);
		Item o = select(rods, grade);
		if (o.name.at(0) == '+')
			o.name.replace(0, 2, select(effects, o.name.at(1) - 48).name);
		ss << o.name << "\n";
	}
	return ss.str();
}