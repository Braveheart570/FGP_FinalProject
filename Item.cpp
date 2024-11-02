#include"Item.h"

Item::Item(string name, int value) {
	m_Name = name;
	m_value = value;
}

string Item::getName() const {
	return m_Name;
}

int Item::getValue() const {
	return m_value;
}