#pragma once
#include <iostream>
#include <string>
#include "Agent.h"
#include <vector>
#include "Definitions.h"
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

	vector<Weapon*> getWeapons() const;

	vector<StackableItem*> getStackbles() const;

	void levelup();

protected:
	string m_Name;
	string const* m_Class;
	int m_Level = 0;
	int m_skillPoints = 2;
	int m_Exp = 0;
	int m_Marksmanship = 1;
	int m_Strength = 1;
	int m_Fortitude = 1;
	int m_Fortune = 1;

	vector<Weapon*> m_Weapons;
	const vector<StackableItem*> m_stackableItems = {
		new StackableItem("potion",50),
		new StackableItem("blade oil",50)
	};
};