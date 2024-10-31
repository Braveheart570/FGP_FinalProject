#pragma once
#include "Item.h"
#include "EffectENUM.h"

class StackableItem : public Item {

public:
	StackableItem(string name, int value, effect itemEffect, int effectPower);

	int getQuantity() const;

	int getEffectPower() const;

	effect getItemEffect() const;

	void addQuantity(int in);

protected:
	int m_Quantity;
	effect m_ItemEffect;
	int m_EffectPower;
};