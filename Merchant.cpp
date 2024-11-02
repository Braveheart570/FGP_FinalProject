#include "Merchant.h"

Merchant::Merchant(string name, string intro) : Npc(name, intro){

}

void Merchant::talk() {
	std::cout << "I'm not interested in talking" << std::endl;
}

vector<StackableItem*> Merchant::getStackbles() const {
	return m_stackableItems;
}