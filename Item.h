#pragma once
#include<string>

using std::string;

class Item {
public:
	Item(string name, int value);

	string getName() const;

	int getValue() const;
protected:
	string m_Name;
	int m_value;
};