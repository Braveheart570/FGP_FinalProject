#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "door.h"
#include "Room.h"


vector<Room*> rooms;

Room* currentRoom;
Room* nextRoom;
string userIn;


int main()
{
    rooms.push_back(new Room());
    rooms.push_back(new Room("a second empty room"));
    rooms[0]->addExit(new Door("old door", rooms[1]));

    currentRoom = rooms[0];
    nextRoom = nullptr;

    while (true) {

        if (nextRoom != nullptr) {
            currentRoom = nextRoom;
            nextRoom = nullptr;
        }

        currentRoom->displayRoom();
        std::getline(std::cin, userIn);
        for (int c = 0; c < currentRoom->getExits().size(); c++) {
            if (currentRoom->getExits()[c]->checkTrigger(userIn)) {
                currentRoom->getExits()[c]->getResponse();
                nextRoom = currentRoom->getExits()[c]->getTargetRoom();
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