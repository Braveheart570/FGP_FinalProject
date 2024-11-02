#pragma once
#include "Npc.h"
#include "stackableItem.h"
#include "Weapon.h"
#include "ToLowerString.h"

class Merchant : public Npc {
public:
	Merchant(string name, string intro);

	virtual void talk();

	vector<StackableItem*> getStackbles() const;

	vector<Weapon*> getWeapons() const;

	void removeWeapon(int index);

	void addWeapon(Weapon* newWeapon);

protected:
	vector<Weapon*> m_Weapons;
	const vector<StackableItem*> m_stackableItems = {
		new StackableItem("Potion",50, EFFECT_PLAYER_HEALTH, 10),
		new StackableItem("Blade oil",50, EFFECT_STRENGTH, 1),
		new StackableItem("Dynamite",50, EFFECT_ENEMY_HEALTH, 50)
	};
};