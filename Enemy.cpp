#include "Enemy.h"

Enemy::Enemy(int health, int damage, int goldReward, int expReward) : Agent(health) {
	m_Damage = damage;
	m_GoldReward = goldReward;
	m_ExpReward = expReward;
}