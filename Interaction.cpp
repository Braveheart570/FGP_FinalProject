#include "Interaction.h"


bool Interaction::checkTrigger(string in) {
	if (in == m_Trigger) {
		return true;
	}
	return false;
}

void Interaction::getResponse() {
	std::cout << m_Response << std::endl;
}

Interaction::Interaction(string trigger, string response) {
	m_Trigger = trigger;
	m_Response = response;
}