#include "Merchant.h"

Merchant::Merchant(string name, string intro) : Npc(name, intro){

}

void Merchant::talk() {
	std::cout << "I'm not interested in talking" << std::endl;
}

vector<StackableItem*> Merchant::getStackbles() const {
	return m_stackableItems;
}

vector<Weapon*> Merchant::getWeapons() const {
	return m_Weapons;
}

void Merchant::removeWeapon(int index) {
	m_Weapons[index] = nullptr;
	m_Weapons.erase(m_Weapons.begin()+index);
}

void Merchant::addWeapon(Weapon* newWeapon) {
	m_Weapons.push_back(newWeapon);
}

int Merchant::getGold() const {
	return m_Gold;
}

void Merchant::addGold(int inGold) {
	m_Gold += inGold;
}