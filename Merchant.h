#pragma once
#include "Npc.h"
#include "item.h"

class Merchant : public Npc {
public:
	Merchant(string name);
protected:
	vector<Item> m_Inventory;
};