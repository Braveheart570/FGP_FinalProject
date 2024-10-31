#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "StatDefinitions.h"
#include "Room.h"
#include "Player.h"
#include "Goblin.h"
#include "Weapon.h"

Weapon* Sword = new Weapon("sword", 10, 10, &statDefs[1]);
Weapon* Gun = new Weapon("Gun", 20, 50, &statDefs[0]);

Player* player;
vector<Room*> rooms;

Enemy* currentEnemy;
Room* currentRoom;
Room* nextRoom;
string userIn;


int main()
{

    player = new Player();
    player->addWeapon(Sword);
    player->addWeapon(Gun);

    rooms.push_back(new Room("dark room", "There is a light in anothe room"));
    
    rooms.push_back(new Room("lit room", "The light is dim but you can see two paths in front of you."));
    
    rooms.push_back(new Room("stairway", "The steps are step, but you climb to a wooden hatch"));
    
    rooms.push_back(new Room("kitchen", "an old kitchen, cold and empty."));
    rooms[3]->addEnemy(new Goblin());



    rooms[0]->addExit(rooms[1]);
    rooms[1]->addExit(rooms[0]);
    rooms[1]->addExit(rooms[2]);
    rooms[1]->addExit(rooms[3]);
    rooms[2]->addExit(rooms[1]);
    rooms[3]->addExit(rooms[2]);
    
    

    currentRoom = rooms[0];
    nextRoom = nullptr;
    currentEnemy = nullptr;

    

    while (true) {

        system("CLS");

        if (nextRoom != nullptr) {
            currentRoom = nextRoom;
            nextRoom = nullptr;
        }
        currentRoom->displayRoom();

        if (currentRoom->getEnemy() != nullptr) {
            std::cout << "entering combat" << std::endl;
            currentEnemy = currentRoom->getEnemy();
        }




        while (currentRoom->getEnemy() != nullptr) {
            
            // use item, flee, use weapon,
            while (true) {
                std::cout << "What do you want to do?" << std::endl;
                std::cout << "Use Item\nUse Weapon\nFlea\n" << std::endl;
                
                std::getline(std::cin, userIn);

                if (userIn == "use item") {
                    //todo
                }
                else if (userIn == "use weapon") {
                    for (int c = 0; c < player->getWeapons().size();c++) {
                        std::cout << player->getWeapons()[c]->getName() << std::endl; 
                    }
                    bool weaponSelected = false;
                    while (weaponSelected == false) {
                        string weaponChoice;
                        std::getline(std::cin, weaponChoice);
                        for (int c = 0; c < player->getWeapons().size(); c++) {
                            if (weaponChoice == player->getWeapons()[c]->getName()) {

                                int playerDmg = player->getDamage(player->getWeapons()[c]);
                                currentEnemy->takeDamage(playerDmg);
                                if (currentEnemy->checkDead()) {
                                    std::cout << "enemy is dead" << std::endl;
                                }
                                else {
                                    std::cout << "enemy still stands" << std::endl;
                                }
                                weaponSelected = true;
                                break;
                            }
                        }
                    }


                }
                else if (userIn == "flea") {
                    //todo
                }
            }
            


            //check for death
            //goblin retaliates

            //check for death

        }



        // next action
        std::cout << "where would you like to go?" << std::endl;
        for (int c = 0; c < currentRoom->getExits().size(); c++) {
            std::cout << currentRoom->getExits()[c]->getName() << std::endl;
        }
        std::getline(std::cin,userIn);
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