#pragma once
#include "Item.h"


class Weapon : public Item {
public:
	Weapon(string name, int value, int dmg,  string const* relatedStat);

	string const* getRelatedStats() const;

	int getDamage() const;

protected:
	int m_Damage;
	 string const* m_RelatedStat;
};