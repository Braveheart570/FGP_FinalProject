#pragma once
#include <iostream>
#include <string>
#include "Agent.h"
#include <vector>
#include "StatDefinitions.h"

#include "Weapon.h"

using std::string;
using std::vector;

class Player : public Agent {
public:
	Player();

	void printStats();

	void addWeapon(Weapon* newWeapon);

	vector<Weapon*> getWeapons() const;

protected:
	string m_Name;
	int m_Level;
	int m_skillPoints;
	int m_Exp;
	int m_Strength;
	int m_Marksmanship;
	int m_Fortitude;
	int m_Fortune;

	vector<Weapon*> m_Weapons;
};