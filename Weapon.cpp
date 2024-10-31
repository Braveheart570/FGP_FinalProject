#include "Weapon.h"

Weapon::Weapon(string name, int value, int dmg,  string const * relatedStat) : Item(name,value) {
	m_Damage = dmg;
	m_RelatedStat = relatedStat;
}

string const * Weapon::getRelatedStats() const {
	return m_RelatedStat;
}

int Weapon::getDamage() const {
	return m_Damage;
}