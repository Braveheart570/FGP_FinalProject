#include "Goblin.h"

Goblin::Goblin() : Enemy(50, 5, 10, 50) {
	
}

int Goblin::getDamage() {
	return m_Damage;
}

string Goblin::getName() const {
	return "Goblin";
}