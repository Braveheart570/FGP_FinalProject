#pragma once
#include<iostream>

#include "Enemy.h"

class Goblin : public Enemy {

public:
	Goblin();
	virtual int getDamage();
	string virtual getName() const;
protected:


};

