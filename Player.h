#pragma once
#include <iostream>
#include <string>
#include "Agent.h"

using std::string;

class Player : public Agent {
public:
	Player();

	void printStats();

protected:
	string m_Name;
	int m_Level;
	int m_skillPoints;
	int m_Exp;
	int m_Strength;
	int m_Marksmanship;
	int m_Fortitude;
	int m_Fortune;
};