#include "Room.h"


Room::Room(string name, string description) {
	m_Description = description;
	m_Name = name;
}

Room::Room(string name, string description, Enemy* enemy) : Room(name, description) {
	m_Enemy = enemy;
}

Room::Room(string name, string description, Npc* npc) : Room(name, description) {
	m_Npc = npc;
}

Room::Room(string name, string description, Merchant* merchant) : Room(name, description) {
	m_Merchant = merchant;
}


void Room::displayRoom() {
	std::cout << "\n---" << m_Name << "---\n" << std::endl;
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

string Room::getName() const {
	return m_Name;
}

Enemy* Room::getEnemy() const {
	return m_Enemy;
}

Merchant* Room::getMerchant() const {
	return m_Merchant;
}

void Room::deleteEnemy() {
	m_Enemy = nullptr;
}

Npc* Room::getNpc() const {
	return m_Npc;
}