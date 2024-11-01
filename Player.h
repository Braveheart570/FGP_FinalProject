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

class Player : public Agent {
public:
	Player();

	void printStats();

	void addWeapon(Weapon* newWeapon);

	int getDamage(Weapon* held);

	int getGold() const;

	string getName() const;

	int getFortune() const;

	void addGold(int inGold);

	void buffStat(effect inEffect, int effectPower);

	vector<Weapon*> getWeapons() const;

	vector<StackableItem*> getStackbles() const;

	void clearBuffs();

	void addExp(int inExp);

	void levelup();

protected:
	string m_Name;
	string const* m_Class;
	int m_Gold = 10;
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
		new StackableItem("potion",50, EFFECT_PLAYER_HEALTH, 10),
		new StackableItem("blade oil",50, EFFECT_STRENGTH, 1),
		new StackableItem("dynamite",50, EFFECT_ENEMY_HEALTH, 50)
	};
};