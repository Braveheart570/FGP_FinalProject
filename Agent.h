#pragma once

// any combat entities including player
class Agent {
public:
	Agent(int maxHealth = 1);
	void takeDamage(int dmg);
protected:
	int m_Health;
	int m_MaxHealth;
	
};