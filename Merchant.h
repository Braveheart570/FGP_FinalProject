#pragma once
#include "Npc.h"
#include "item.h"

class Merchant : public Npc {
public:
	Merchant(string name, string intro);

	virtual void talk();

protected:
	vector<Item> m_Inventory;
};