#include "Enemy.h"

Enemy::Enemy(string name, int health, int damage, int goldReward, int expReward, int fleaChance) : Agent(health) {
	m_Name = name;
	m_Damage = damage;
	m_GoldReward = goldReward;
	m_ExpReward = expReward;
	m_fleaChance = fleaChance;
}

string Enemy::getName() const {
	return m_Name;
}

int Enemy::getGoldReward() const {
	return m_GoldReward;
}

int Enemy::getExpReward() const {
	return m_ExpReward;
}

int Enemy::getFleaChance() const {
	return m_fleaChance;
}