#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "Enemy.h"

using std::vector;
using std::string;

class Room {
public:
	Room(string name = "Empty room", string description = "Strange, it's almost like someone forgot to put something here.");

	void displayRoom();

	Enemy* getEnemy() const;

	void addExit(Room* newExit);

	vector<Room*> getExits() const ;

	string getDesc() const ;

	string getName() const;

	void addEnemy(Enemy* enemyIn);

protected:
	string m_Name;
	string m_Description;
	Enemy* m_Enemy;
	//add npc class
	vector<Room*> m_Exits;
};