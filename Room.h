#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "Agent.h"

using std::vector;
using std::string;

class Room {
public:
	Room(string description = "an empty room");

	void displayRoom();

	vector<Agent*> getAgents() const;

	void addExit(Room* newExit);

	vector<Room*> getExits() const ;

	string getDesc() const ;

protected:
	string m_Description;
	vector<Agent*> m_Agents;
	vector<Room*> m_Exits;
};