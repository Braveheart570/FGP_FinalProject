#include "Goblin.h"

Goblin::Goblin() : Enemy("goblin",50, 5, 10, 50) {
	
}

int Goblin::getDamage() {
	return m_Damage;
}