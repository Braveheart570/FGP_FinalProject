#include "Enemy.h"

Enemy::Enemy(string name, int health, int damage, int goldReward, int expReward) : Agent(health) {
	m_Name = name;
	m_Damage = damage;
	m_GoldReward = goldReward;
	m_ExpReward = expReward;
}

string Enemy::getName() const {
	return m_Name;
}