#include "Agent.h"

Agent::Agent(int maxHealth) {
	m_Health = maxHealth;
	m_MaxHealth = maxHealth;
}

void Agent::takeDamage(int dmg) {
	m_Health -= dmg;
}