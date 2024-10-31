#include "StackableItem.h"

StackableItem::StackableItem(string name, int value) : Item(name, value), m_Quantity(0) {

}

int StackableItem::getQuantity() const {
	return m_Quantity;
}

void StackableItem::addQuantity(int in) {
	m_Quantity += in;
}