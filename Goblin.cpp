#include "Goblin.h"

Goblin::Goblin() : Enemy(50, 5, 10) {
	
}

void Goblin::taunt() {
	std::cout << "growl" << std::endl;
}