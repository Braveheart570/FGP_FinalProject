#pragma once
#include "Agent.h"

class Enemy : public Agent {
public:
	Enemy(string name, int health = 1, int damage = 0, int goldReward = 0, int expReward = 0, int fleaChance = 100);

	int getDamage() const;

	string getName() const;


	int getGoldReward() const;

	int getExpReward() const;

	int getFleaChance() const;


protected:
	int m_fleaChance;
	int m_Damage;
	int m_ExpReward;
	int m_GoldReward;
	string m_Name;
};