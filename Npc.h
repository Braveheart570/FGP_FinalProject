#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iostream>
using std::string;
using std::vector;



struct Dialogue {
	Dialogue(string question, string awnser) {
		m_Question = question;
		m_Awnser = awnser;
	}
	string m_Question;
	string m_Awnser;
};




class Npc {

public:
	Npc(string name, string m_Intro);

	void greet();

	string getName() const;

	virtual void talk();

	void addDialgue(Dialogue* dialogue);

protected:
	string m_Name;
	string m_Intro;
	vector<Dialogue*> m_Dialogue;

};