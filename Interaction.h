#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;


class Interaction {
public:
	Interaction(string trigger, string response);

	void getResponse();

	bool checkTrigger(string in);

protected:
	string m_Trigger;
	string m_Response;
};