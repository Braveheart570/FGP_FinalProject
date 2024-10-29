#include "Enemy.h"

Enemy::Enemy(int health, int damage, int goldReward) : Agent(health) {
	m_Damage = damage;
	m_GoldReward = goldReward;
}