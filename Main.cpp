#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "Room.h"
#include "Goblin.h"
#include "Player.h"

Player* player;
vector<Room*> rooms;

Room* currentRoom;
Room* nextRoom;
string userIn;


int main()
{

    player = new Player();

    rooms.push_back(new Room("dark room", "There is a light in anothe room"));
    
    rooms.push_back(new Room("lit room", "The light is dim but you can see two paths in front of you."));
    
    rooms.push_back(new Room("stairway", "The steps are step, but you climb to a wooden hatch"));
    
    rooms.push_back(new Room("kitchen", "an old kitchen, cold and empty."));
    rooms[3]->addAgent(new Goblin);

    rooms[0]->addExit(rooms[1]);
    rooms[1]->addExit(rooms[0]);
    rooms[1]->addExit(rooms[2]);
    rooms[1]->addExit(rooms[3]);
    rooms[2]->addExit(rooms[1]);
    rooms[3]->addExit(rooms[2]);
    
    

    currentRoom = rooms[0];
    nextRoom = nullptr;


    

    while (true) {

        if (nextRoom != nullptr) {
            currentRoom = nextRoom;
            nextRoom = nullptr;
        }
        currentRoom->displayRoom();

        if (currentRoom->getAgents().size() > 0) {
            std::cout << "entering combat" << std::endl;
        }

        while (currentRoom->getAgents().size() > 0) {
            
        }



        // next action
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