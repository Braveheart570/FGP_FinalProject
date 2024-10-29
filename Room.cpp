#include "Room.h"


Room::Room(string description) {
	m_Description = description;
}


void Room::displayRoom() {
	std::cout << m_Description << std::endl;
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