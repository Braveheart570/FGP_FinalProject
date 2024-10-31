#include "Goblin.h"

Goblin::Goblin() : Enemy(50, 5, 10) {
	
}

int Goblin::getDamage() {
	return m_Damage;
}