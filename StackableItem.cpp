#include "StackableItem.h"

StackableItem::StackableItem(string name, int value, effect itemEffect, int effectPower) : Item(name, value), m_Quantity(0), m_ItemEffect(itemEffect), m_EffectPower(effectPower) {

}

int StackableItem::getQuantity() const {
	return m_Quantity;
}

int StackableItem::getEffectPower() const {
	return m_EffectPower;
}

void StackableItem::addQuantity(int in) {
	m_Quantity += in;
}

effect StackableItem::getItemEffect() const {
	return m_ItemEffect;
}