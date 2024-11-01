#include "Npc.h"
#include "ToLowerString.h"

Npc::Npc(string name, string intro) {
	m_Name = name;
	m_Intro = intro;
}

void Npc::greet() {
	std::cout << " --- " << m_Name << " --- " << std::endl;
	std::cout << m_Intro << std::endl;
}

string Npc::getName() const {
	return m_Name;
}

void Npc::talk() {
	string userIn;
	bool questionAsked;
	system("CLS");
	greet();
	while (true) {
		
		std::cout << "\nask:" << std::endl;
		for (int c = 0; c < m_Dialogue.size();c++) {
			std::cout << m_Dialogue[c]->m_Question << std::endl;
		}

		std::getline(std::cin, userIn);
		userIn = toLowerString(userIn);

		if (userIn == "back") {
			break;
		}

		questionAsked = false;
		for (int c = 0; c < m_Dialogue.size(); c++) {
			if (userIn == toLowerString(m_Dialogue[c]->m_Question)) {
				questionAsked = true;
				system("CLS");
				greet();
				std::cout << "\n" << m_Dialogue[c]->m_Awnser << std::endl;

				break;
			}
		}

		if (questionAsked == false) {
			system("CLS");
			greet();
		}

	}
}

void Npc::addDialgue(Dialogue* dialogue) {
	m_Dialogue.push_back(dialogue);
}