#include "Room.h"


Room::Room(string description = "an empty room") {
	m_Description = description;
}


void Room::displayRoom() {
	std::cout << m_Description << std::endl;
}

vector<Door*> Room::getExits() const {
	return m_Exits;
}

void Room::addExit(Door* newExit) {
	m_Exits.push_back(newExit);
}