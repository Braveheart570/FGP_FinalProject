#include "Agent.h"

Agent::Agent(int maxHealth) : m_Health(maxHealth), m_MaxHealth(maxHealth){
}

void Agent::takeDamage(int dmg) {
	m_Health = m_Health - dmg;
}

bool Agent::checkDead() {
	if (m_Health <= 0) {
		return true;
	}
	else {
		return false;
	}
}