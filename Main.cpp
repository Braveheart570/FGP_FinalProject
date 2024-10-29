#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "Room.h"


vector<Room*> rooms;

Room* currentRoom;
Room* nextRoom;
string userIn;


int main()
{
    rooms.push_back(new Room());
    rooms.push_back(new Room("room 2", "Who would have thought"));
    rooms[0]->addExit(rooms[1]);
    rooms[1]->addExit(rooms[0]);

    currentRoom = rooms[0];
    nextRoom = nullptr;


    

    while (true) {

        if (nextRoom != nullptr) {
            currentRoom = nextRoom;
            nextRoom = nullptr;
        }

        currentRoom->displayRoom();
        std::getline(std::cin, userIn);
        for (int c = 0; c < currentRoom->getExits().size();c++) {
            if (userIn == currentRoom->getExits()[c]->getName()) {
                nextRoom = currentRoom->getExits()[c];
                break;
            }
        }
    }
    


}

//room class
//door states
//location
//description
//npcs
//enemies

//npc class

//enemy class

//player class

//item class

//weapon class extends item

//entity class?

//merchant class extends npc