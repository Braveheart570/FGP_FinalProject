#include "Goblin.h"

Goblin::Goblin() : Enemy("goblin",50, 70, 10, 110) {
	
}

int Goblin::getDamage() {
	return m_Damage;
}