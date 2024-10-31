#pragma once
#include <string>
#include <vector>
#include "StackableItem.h"

using std::vector;
using std::string;

const string statDefs[4] = {
	"Marksmanship",
	"Strength",
	"Fortitude",
	"Fortune"
};

const string statDefsLower[4] = {
	"marksmanship",
	"strength",
	"fortitude",
	"fortune"
};

const string classNames[4] = {
	"Duelist",
	"Brawler",
	"Juggernaut",
	"Fool"
};

const string classNamesLower[4] = {
	"duelist",
	"brawler",
	"juggernaut",
	"fool"
};

const vector<const StackableItem*> InventoryTemplate = { // NOT CURRENTLY IN USE MAY NOT NEED
	new StackableItem("potion",50),
	new StackableItem("blade oil",50)

};