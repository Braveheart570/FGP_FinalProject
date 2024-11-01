#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using std::vector;
using std::string;

#include "Definitions.h"
#include "ToLowerString.h"
#include "Room.h"
#include "Player.h"
#include "Goblin.h"
#include "Weapon.h"


Weapon* Sword = new Weapon("sword", 10, 10, &statDefs[1]);
Weapon* Gun = new Weapon("gun", 20, 50, &statDefs[0]);

Player* player;
vector<Room*> rooms;

Npc* currentNpc;
Enemy* currentEnemy;
Room* currentRoom;
Room* nextRoom;
Room* lastRoom;
string userIn;

void isCurrentEnemyDead();


int main()
{

    player = new Player();
    player->addWeapon(Sword);
    player->addWeapon(Gun);
    player->getStackbles()[0]->addQuantity(1);
    player->getStackbles()[1]->addQuantity(1);
    player->getStackbles()[2]->addQuantity(1);

    rooms.push_back(new Room("dark room", "There is a light in anothe room"));
    
    rooms.push_back(new Room("lit room", "The light is dim but you can see two paths in front of you."));
    
    rooms.push_back(new Room("stairway", "The steps are step, but you climb to a wooden hatch"));
    
    rooms.push_back(new Room("kitchen", "an old kitchen, cold and empty.", new Goblin()));

    rooms.push_back(new Room("pantry", "A small empty pantry.", new Npc("Old Man", "A scared old man hiding in a pantry")));

    rooms.push_back(new Room("empty field", "an open patch of land with a wooden hatch on the ground."));


    rooms[0]->addExit(rooms[1]);

    rooms[1]->addExit(rooms[0]);
    rooms[1]->addExit(rooms[2]);
    rooms[1]->addExit(rooms[3]);

    rooms[2]->addExit(rooms[1]);
    rooms[2]->addExit(rooms[5]);

    rooms[3]->addExit(rooms[1]);
    rooms[3]->addExit(rooms[4]);

    rooms[4]->addExit(rooms[3]);

    rooms[5]->addExit(rooms[2]);
    

    currentRoom = rooms[0];
    nextRoom = nullptr;
    currentEnemy = nullptr;
    currentNpc = nullptr;
    lastRoom = nullptr;

    

    while (true) {

        

        if (nextRoom != nullptr) {
            lastRoom = currentRoom;
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
            std::cout << currentEnemy->getName() << " confronted you in the " << currentRoom->getName() << "." << std::endl;
        }
        else {
            currentEnemy = nullptr;
        }

        while (currentEnemy != nullptr) {
            
            // use item, flee, use weapon,

                std::cout << "\nYour health: " << player->getHealth() << "/" << player->getMaxHealth() << "         " << currentEnemy->getName() << " health: " << currentEnemy->getHealth() << "/" << currentEnemy->getMaxHealth() << std::endl;

                std::cout << "\nWhat do you want to do?\n" << std::endl;
                std::cout << "-Use Item\n-Use Weapon\n-Flee\n" << std::endl;
                
                std::getline(std::cin, userIn);
                userIn = toLowerString(userIn);

                if (userIn == "use item") {
                    for (int c = 0; c < player->getStackbles().size(); c++) {
                        std::cout << player->getStackbles()[c]->getName() << string(20 - player->getStackbles()[c]->getName().length(), ' ') << player->getStackbles()[c]->getQuantity() << std::endl;
                    }
                    bool itemSelected = false;
                    while (itemSelected == false) {

                        string itemChoice;
                        std::getline(std::cin, itemChoice);
                        itemChoice = toLowerString(itemChoice);

                        for (int c = 0; c < player->getStackbles().size(); c++) {
                            if (itemChoice == player->getStackbles()[c]->getName() && player->getStackbles()[c]->getQuantity() > 0) {

                                system("CLS");
                                std::cout << player->getStackbles()[c]->getName() << " used." << std::endl;

                                switch (player->getStackbles()[c]->getItemEffect()) {

                                case EFFECT_PLAYER_HEALTH:
                                    player->takeDamage(player->getStackbles()[c]->getEffectPower() * -1);
                                    break;
                                case EFFECT_ENEMY_HEALTH:

                                    currentEnemy->takeDamage(player->getStackbles()[c]->getEffectPower());

                                    isCurrentEnemyDead();

                                    break;
                                case EFFECT_MARKSMANSHIP:
                                    player->buffStat(player->getStackbles()[c]->getItemEffect(), player->getStackbles()[c]->getEffectPower());
                                    break;
                                case EFFECT_STRENGTH:
                                    player->buffStat(player->getStackbles()[c]->getItemEffect(), player->getStackbles()[c]->getEffectPower());
                                    break;
                                case EFFECT_FORTITUDE:
                                    player->buffStat(player->getStackbles()[c]->getItemEffect(), player->getStackbles()[c]->getEffectPower());
                                    break;
                                case EFFECT_FORTUNE:
                                    player->buffStat(player->getStackbles()[c]->getItemEffect(), player->getStackbles()[c]->getEffectPower());
                                    break;
                                }

                                

                                
                                player->getStackbles()[c]->addQuantity(-1);
                                itemSelected = true;
                                break;
                            }

                            

                        }

                        if (itemChoice == "back") {
                            system("CLS");
                            break;
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
                        weaponChoice = toLowerString(weaponChoice);

                        for (int c = 0; c < player->getWeapons().size(); c++) {
                            if (weaponChoice == player->getWeapons()[c]->getName()) {

                                int playerDmg = player->getDamage(player->getWeapons()[c]);
                                currentEnemy->takeDamage(playerDmg);

                                player->clearBuffs();

                                system("CLS");

                                isCurrentEnemyDead();

                                if(currentEnemy != nullptr) {

                                    //Enemy attacks after player uses their weapon

                                    std::cout << currentEnemy->getName() << " Attacks!" << std::endl;
                                    player->takeDamage(currentEnemy->getDamage());
                                    
                                    if (player->getHealth() <= 0) {
                                        std::cout << "--------------" << std::endl;
                                        std::cout << " - YOU DIED - " << std::endl;
                                        std::cout << "--------------" << std::endl;
                                        return 0;
                                    }


                                }

                                weaponSelected = true;
                                break;
                            }
                        }

                        if (weaponChoice == "back") {
                            system("CLS");
                            break;
                        }

                    }


                }
                else if (userIn == "flee") {

                    // number between 100 and 1
                    int randomNum = rand() % 101;

                    if (randomNum <= currentEnemy->getFleaChance()) {
                        system("CLS");
                        std::cout << "you escaped!" << std::endl;
                        currentEnemy = nullptr;
                        nextRoom = lastRoom;
                    }
                    else {
                        system("CLS");
                        std::cout <<"You failed to flee." << std::endl;

                        std::cout << currentEnemy->getName() << " Attacks!" << std::endl;
                        player->takeDamage(currentEnemy->getDamage());

                        if (player->getHealth() <= 0) {
                            std::cout << "--------------" << std::endl;
                            std::cout << " - YOU DIED - " << std::endl;
                            std::cout << "--------------" << std::endl;
                            return 0;
                        }
                    }

                    
                }
                else {
                    system("CLS");
                }



                


        }

        // this is in case we fled a combat encounter
        if (nextRoom != nullptr) {
            continue;
        }

        
        
        currentRoom->displayRoom();

        if (currentRoom->getNpc() != nullptr) {
            currentNpc = currentRoom->getNpc();
            currentNpc->greet();
        }

        // mavigation

        std::cout << "\nwhere would you like to go?\n" << std::endl;
        for (int c = 0; c < currentRoom->getExits().size(); c++) {
            std::cout << " - " << currentRoom->getExits()[c]->getName() << std::endl;
        }
        std::getline(std::cin,userIn);
        userIn = toLowerString(userIn);
        for (int c = 0; c < currentRoom->getExits().size();c++) {
            if (userIn == currentRoom->getExits()[c]->getName()) {
                nextRoom = currentRoom->getExits()[c];
                break;
            }
        }

        system("CLS");
    }
    


}





void isCurrentEnemyDead() {
    if (currentEnemy->checkDead()) {
        std::cout << currentEnemy->getName() << " is dead" << std::endl;

        int goldReward = std::floor(currentEnemy->getGoldReward() + (currentEnemy->getGoldReward() / 10) * player->getFortune());
        int expReward = std::floor(currentEnemy->getExpReward() + (currentEnemy->getExpReward() / 10) * player->getFortune());

        std::cout << player->getName() << " earned " << goldReward << " gold and " << expReward << " exp." << std::endl;

        player->addGold(goldReward);
        player->addExp(expReward);

        currentRoom->deleteEnemy();
        currentEnemy = nullptr;
    }
    else {
        std::cout << currentEnemy->getName() << " still stands" << std::endl;
    }
}