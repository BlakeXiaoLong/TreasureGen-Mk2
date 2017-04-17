#pragma once
#include <time.h>
#include <string>
#include <time.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "Item.h"
#include "Armor.h"
#include "Atlas.h"
#include "Weapon.h"
#include "Windows.h"
#include "PricedItem.h"
#include "LevelledItem.h"

enum Coin { cp, sp, gp, pp }; // ranges from 0 to 3
enum Grade { mwk, LMi, GMi, LMe, GMe, LMa, GMa }; // ranges from 0 to 6
int roll(int num, int die, int multiplier = 1);
template <class T> T select(vector<vector<T>> atlases, int grade);
string coinGen(int num, int die, Coin coin = gp, int multiplier = 1);
string gemGen(Grade grade, int num = 1);
string artGen(Grade grade, int num = 1);
string scrollGen(Grade grade, int num = 1);
string wandGen(Grade grade, int num = 1);
string potionGen(Grade grade, int num = 1);
string armorGen(Grade grade, int num = 1);  // grade = 0 for masterwork
string weaponGen(Grade grade, int num = 1); // ^
string ringGen(Grade grade, int num = 1);
string wondrousGen(Grade grade, int num = 1);
string staffGen(Grade grade, int num = 1);
string rodGen(Grade grade, int num = 1);