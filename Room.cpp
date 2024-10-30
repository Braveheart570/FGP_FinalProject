#include "Room.h"


Room::Room(string name, string description) {
	m_Description = description;
	m_Name = name;
	m_Enemy = nullptr;
}


void Room::displayRoom() {
	std::cout << m_Name << std::endl;
	std::cout << m_Description << "\n" << std::endl;
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

void Room::addEnemy(Enemy* inEnemy) {
	m_Enemy = inEnemy;
}

Enemy* Room::getEnemy() const {
	return m_Enemy;
}