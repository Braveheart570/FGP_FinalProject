#pragma once
#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;

class Npc {

public:
	Npc(string name, string m_Intro);

	void greet();

protected:
	string m_Name;
	string m_Intro;

};