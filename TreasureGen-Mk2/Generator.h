#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <fstream>

#include "Windows.h"
#include "Item.h"
#include "LevelledItem.h"
#include "Weapon.h"
#include "Armor.h"
#include "Atlas.h"

enum Coin { cp, sp, gp, pp };
enum Grade { LMi, GMi, LMe, GMe, LMa, GMa };
stringstream coinGen(int num, int die, Coin = gp, int multiplier = 1);
stringstream gemGen(int grade, int num = 1);
stringstream artGen(int grade, int num = 1);
stringstream scrollGen(Grade grade, int num = 1);
stringstream wandGen(Grade grade, int num = 1);
stringstream potionGen(Grade grade, int num = 1);
stringstream armorGen(Grade grade, int num = 1); // grade = 0 for masterwork
stringstream weaponGen(Grade grade, int num = 1); // ^
stringstream ringGen(Grade grade, int num = 1);
stringstream wondrousGen(Grade grade, int num = 1);
stringstream staffGen(Grade grade, int num = 1);
stringstream rodGen(Grade grade, int num = 1);