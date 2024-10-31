#include "Goblin.h"

Goblin::Goblin() : Enemy("goblin",50, 5, 10, 110) {
	
}

int Goblin::getDamage() {
	return m_Damage;
}