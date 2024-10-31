#pragma once
#include<string>
using std::string;

// any combat entities, including player
class Agent {
public:
	Agent(int maxHealth = 1);
	void takeDamage(int dmg);
	bool checkDead();

	int getHealth() const;

	int getMaxHealth() const;

protected:
	int m_Health;
	int m_MaxHealth;
	
};