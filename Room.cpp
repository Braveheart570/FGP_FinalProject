#include "Room.h"


Room::Room(string name, string description) {
	m_Description = description;
	m_Name = name;
}


void Room::displayRoom() {
	std::cout << m_Name << std::endl;
	std::cout << m_Description << "\n" << std::endl;
	for (int c = 0; c < m_Exits.size(); c++) {
		std::cout << m_Exits[c]->getName() << std::endl;
	}
}

void Room::addExit(Room* newExit) {
	m_Exits.push_back(newExit);
}

vector<Room*> Room::getExits() const {
	return m_Exits;
}

string Room::getDesc() const {
	return m_Description;
}

string Room::getName() const {
	return m_Name;
}

void Room::addAgent(Agent* newAgent) {
	m_Agents.push_back(newAgent);
}