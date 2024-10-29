#pragma once
#include "Item.h"


class Weapon : public Item {
public:
	Weapon();
protected:
	int m_Damage;
};