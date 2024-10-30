#pragma once
#include "Item.h"


class Weapon : public Item {
public:
	Weapon(string name, int value, int dmg,  string relatedStat);
protected:
	int m_Damage;
	string m_RelatedStat;
};