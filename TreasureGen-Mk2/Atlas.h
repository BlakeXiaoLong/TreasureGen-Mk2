#pragma once
#include <vector>
#include <string>

#include "Item.h"
#include "PricedItem.h"
#include "LevelledItem.h"
#include "Weapon.h"
#include "Armor.h"

void buildEverything(vector<Armor> &armor, vector<Weapon> &weapons, vector<vector<PricedItem>> &art, vector<vector<Item>> &gems, vector<vector<LevelledItem>> &wands, vector<vector<LevelledItem>> &scroll, vector<vector<LevelledItem>> &potions,
	vector<vector<Item>> &staffs, vector<vector<Item>> &metamagic, vector<vector<Item>> &rings, vector<vector<Item>> &wondrous, vector<vector<Item>> &effects, vector<vector<Item>> &enchantments, vector<vector<Item>> &specifics);
void buildArmor(vector<Armor> &atlas);
void buildWeapon(vector<Weapon> &atlas);
void buildArt(vector<vector<PricedItem>> &atlas);
void buildGem(vector<vector<Item>> &atlas);
void buildWand(vector<vector<LevelledItem>> &atlas);
void buildScroll(vector<vector<LevelledItem>> &atlas);
void buildPotion(vector<vector<LevelledItem>> &atlas);
void buildStaff(vector<vector<Item>> &atlas);
void buildMetamagic(vector<vector<Item>> &atlas);
void buildEffect(vector<vector<Item>> &atlases);
void buildRing(vector<vector<Item>> &atlas);
void buildWondrous(vector<vector<Item>> &atlas);
void buildEnchantments(vector<vector<Item>> &atlas);
void buildSpecifics(vector<vector<Item>> &atlas);