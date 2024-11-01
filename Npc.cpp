#include "Npc.h"

Npc::Npc(string name, string intro) {
	m_Name = name;
	m_Intro = intro;
}

void Npc::greet() {
	std::cout << " --- " << m_Name << " --- " << std::endl;
	std::cout << m_Intro << std::endl;
}