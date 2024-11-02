#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "Enemy.h"
#include "Merchant.h"

using std::vector;
using std::string;

class Room {
public:
	Room(string name, string description);

	Room(string name, string description, Enemy* enemy);

	Room(string name, string description, Npc* npc);

	Room(string name, string description, Merchant* merchant);

	void displayRoom();

	Enemy* getEnemy() const;

	Npc* getNpc() const;

	Merchant* getMerchant() const;

	void addExit(Room* newExit);

	vector<Room*> getExits() const ;

	string getDesc() const ;

	string getName() const;

	void deleteEnemy();

protected:
	string m_Name;
	string m_Description;
	Enemy* m_Enemy;
	Npc* m_Npc;
	Merchant* m_Merchant;
	
	vector<Room*> m_Exits;
};