#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "Agent.h"

using std::vector;
using std::string;

class Room {
public:
	Room(string name = "Empty room", string description = "Strange, it's almost like someone forgot to put something here.");

	void displayRoom();

	vector<Agent*> getAgents() const;

	void addExit(Room* newExit);

	vector<Room*> getExits() const ;

	string getDesc() const ;

	string getName() const;

	void addAgent(Agent* newAgent);

protected:
	string m_Name;
	string m_Description;
	vector<Agent*> m_Agents;
	vector<Room*> m_Exits;
};