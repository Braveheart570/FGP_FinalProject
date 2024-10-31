#pragma once
#include "Item.h"

class StackableItem : public Item {

public:
	StackableItem(string name, int value);

	int getQuantity() const;

	void addQuantity(int in);

protected:
	int m_Quantity;

};