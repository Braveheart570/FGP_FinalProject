#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "Agent.h"
#include "Door.h"

using std::vector;
using std::string;

class Room {
public:
	Room(string description = "an empty room");

	void displayRoom();

	vector<Agent*> getAgents() const;

	void addExit(Door* newExit);

	vector<Door*> getExits() const;

protected:
	string m_Description;
	vector<Door*> m_Exits;
	vector<Agent*> m_Agents;
};