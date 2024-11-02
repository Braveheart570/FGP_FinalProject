#pragma once
#include <iostream>
#include <string>
#include "Agent.h"
#include <vector>
#include "Definitions.h"
#include "ToLowerString.h"
#include "StackableItem.h"
#include "Weapon.h"

using std::string;
using std::vector;

//in hind sight I should have had player and merchant share a base class instead of player and enemy
// too late to change that now.

class Player : public Agent {
public:
	Player();

	void printStats();

	void addWeapon(Weapon* newWeapon);

	void removeWeapon(int index);

	int getDamage(Weapon* held);

	int getGold() const;

	string getName() const;

	int getFortune() const;

	void addGold(int inGold);

	void buffStat(effect inEffect, int effectPower);

	vector<Weapon*> getWeapons() const;

	vector<StackableItem*> getStackbles() const;

	void clearBuffs(bool fortune);

	void addExp(int inExp);

	void levelup();


protected:
	string m_Name;
	string const* m_Class;
	int m_Gold = 50;
	int m_Level = 0;
	int m_skillPoints = 2;
	int m_Exp = 0;
	int m_Marksmanship = 1;
	int m_Strength = 1;
	int m_Fortitude = 1;
	int m_Fortune = 1;

	int m_MarksmanshipBuff = 0;
	int m_StrengthBuff = 0;
	int m_FortitudeBuff = 0;
	int m_FortuneBuff = 0;

	vector<Weapon*> m_Weapons;

	const vector<StackableItem*> m_stackableItems = {
		new StackableItem("Potion",10, EFFECT_PLAYER_HEALTH, 10),
		new StackableItem("Blade oil",50, EFFECT_STRENGTH, 1),
		new StackableItem("Dynamite",50, EFFECT_ENEMY_HEALTH, 50),
		new StackableItem("Lucky Stone",50, EFFECT_FORTUNE, 100)
	};
};