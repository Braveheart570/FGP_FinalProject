#pragma once
#include "Agent.h"

class Enemy : public Agent {
public:
	Enemy(int health = 1, int damage = 0, int goldReward = 0);
protected:
	int m_Damage;
	int m_ExpReward;
	int m_GoldReward;
};