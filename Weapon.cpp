#include "Weapon.h"

Weapon::Weapon(string name, int value, int dmg,  string relatedStat) : Item(name,value) {
	m_Damage = dmg;
	m_RelatedStat = relatedStat;
}