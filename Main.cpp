#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "Definitions.h"
#include "Room.h"
#include "Player.h"
#include "Goblin.h"
#include "Weapon.h"

//Consumable* BladeOil = new Consumable("blade oil");

Weapon* Sword = new Weapon("sword", 10, 10, &statDefs[1]);
Weapon* Gun = new Weapon("gun", 20, 50, &statDefs[0]);

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
    player->getStackbles()[0]->addQuantity(1);
    player->getStackbles()[1]->addQuantity(1);

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

        

        if (nextRoom != nullptr) {
            currentRoom = nextRoom;
            nextRoom = nullptr;
        }

        if (currentRoom->getEnemy() != nullptr) {
            system("CLS");
            string combatMessage = "A Foe Stands before you!";
            std::cout << string(combatMessage.length(), '-') << std::endl;
            std::cout << combatMessage << std::endl;
            std::cout << string(combatMessage.length(), '-') << std::endl;
            currentEnemy = currentRoom->getEnemy();
            std::cout << "A " << currentEnemy->getName() << " confronted you in the " << currentRoom->getName() << "." << std::endl;
        }
        else {
            currentEnemy = nullptr;
        }

        while (currentEnemy != nullptr) {
            
            // use item, flee, use weapon,
            while (true) {

                std::cout << "\nYour health: " << player->getHealth() << "/" << player->getMaxHealth() << "         " << currentEnemy->getName() << " health: " << currentEnemy->getHealth() << "/" << currentEnemy->getMaxHealth() << std::endl;

                std::cout << "\nWhat do you want to do?\n" << std::endl;
                std::cout << "-Use Item\n-Use Weapon\n-Flea\n" << std::endl;
                
                std::getline(std::cin, userIn);

                if (userIn == "use item") {
                    for (int c = 0; c < player->getStackbles().size(); c++) {
                        std::cout << player->getStackbles()[c]->getName() << string(20 - player->getStackbles()[c]->getName().length(), ' ') << player->getStackbles()[c]->getQuantity() << std::endl;
                    }
                    bool itemSelected = false;
                    while (itemSelected == false) {
                        string itemChoice;
                        std::getline(std::cin, itemChoice);
                        for (int c = 0; c < player->getStackbles().size(); c++) {
                            if (itemChoice == player->getStackbles()[c]->getName() && player->getStackbles()[c]->getQuantity() > 0) {

                                std::cout << player->getStackbles()[c]->getName() << " used." << std::endl; // this is getting skipped
                                player->getStackbles()[c]->addQuantity(-1);
                                itemSelected = true;
                                break;
                            }
                        }
                    }
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

                                system("CLS");

                                if (currentEnemy->checkDead()) {
                                    std::cout << "enemy is dead" << std::endl;
                                    currentRoom->deleteEnemy();
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

                system("CLS");

            }
            

            


        }



        // next action
        system("CLS");
        currentRoom->displayRoom();


        std::cout << "\nwhere would you like to go?\n" << std::endl;
        for (int c = 0; c < currentRoom->getExits().size(); c++) {
            std::cout << " - " << currentRoom->getExits()[c]->getName() << std::endl;
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