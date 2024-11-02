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
#include "Merchant.h"


Weapon* Sword = new Weapon("sword", 10, 10, &statDefs[1]);
Weapon* Gun = new Weapon("gun", 20, 50, &statDefs[0]);

Player* player;
vector<Room*> rooms;

Npc* currentNpc;
Enemy* currentEnemy;
Room* currentRoom;
Merchant* currentMerchant;
Room* nextRoom;
Room* lastRoom;
string userIn;

void isCurrentEnemyDead();

void linkRooms(Room* room1, Room* room2);

bool yesNoQuestion(string question);

int main()
{

    player = new Player();
    player->addWeapon(Sword);
    player->addWeapon(Gun);
    player->getStackbles()[0]->addQuantity(1);
    player->getStackbles()[1]->addQuantity(1);
    player->getStackbles()[2]->addQuantity(1);

    rooms.push_back(new Room("Dark Room", "There is a light in anothe room"));
    
    rooms.push_back(new Room("Lit Room", "The light is dim but you can see two paths in front of you."));
    
    rooms.push_back(new Room("Stairway", "The steps are step, but you climb to a wooden hatch"));
    
    rooms.push_back(new Room("Kitchen", "an old kitchen, cold and empty.", new Goblin()));

    rooms.push_back(new Room("Pantry", "A small empty pantry with an old man hiding in it.", new Npc("Old Man", "A scared old man hiding in a pantry")));
    rooms[4]->getNpc()->addDialgue(new Dialogue("What are you doing here?", "Hiding from that thing. But you saved me, thanks you!"));
    rooms[4]->getNpc()->addDialgue(new Dialogue("Do you know how to get out of here?", "Go back the way you came and take the stairs."));

    rooms.push_back(new Room("Empty Field", "an open patch of land with a wooden hatch on the ground. You see a tent in the distance set up next to a cart full of goods."));

    rooms.push_back(new Room("Merchant tent", "The camp of a traveling merchant", new Merchant("Traveling Merchant", "His eyes glisten at the sight of a potential customer.")));
    rooms[6]->getMerchant()->getStackbles()[0]->addQuantity(3);
    rooms[6]->getMerchant()->getStackbles()[1]->addQuantity(1);

    Npc* test = new Merchant("", "");


    linkRooms(rooms[0], rooms[1]);
    linkRooms(rooms[1], rooms[2]);
    linkRooms(rooms[1], rooms[3]);
    linkRooms(rooms[2], rooms[5]);
    linkRooms(rooms[3], rooms[4]);
    linkRooms(rooms[5], rooms[6]);
    

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
                        if (player->getStackbles()[c]->getQuantity() <= 0) {
                            continue;
                        }
                        std::cout << player->getStackbles()[c]->getName() << string(20 - player->getStackbles()[c]->getName().length(), ' ') << player->getStackbles()[c]->getQuantity() << std::endl;
                    }
                    bool itemSelected = false;
                    while (itemSelected == false) {

                        string itemChoice;
                        std::getline(std::cin, itemChoice);
                        itemChoice = toLowerString(itemChoice);

                        for (int c = 0; c < player->getStackbles().size(); c++) {
                            if (itemChoice == toLowerString(player->getStackbles()[c]->getName()) && player->getStackbles()[c]->getQuantity() > 0) {

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
                        std::cout << toLowerString(player->getWeapons()[c]->getName()) << std::endl;
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

        // npc
        if (currentRoom->getNpc() != nullptr) {
            currentNpc = currentRoom->getNpc();
            
            if (yesNoQuestion(currentNpc->getName() + " is here. Would you like to talk to them?")) {
                currentNpc->talk();
                system("CLS");
                currentRoom->displayRoom();
            }
        }
        else {
            currentNpc = nullptr;
        }



        //merchant

        if (currentRoom->getMerchant() != nullptr) {
            currentMerchant = currentRoom->getMerchant();
            
            if (yesNoQuestion(currentMerchant->getName() + " is here. Would you like to trade with them?")) {


                system("CLS");
                currentMerchant->greet();


                while (true) {

                    std::cout << "\nWhat kind of Item's would you like to trade?\nWeapons\nItems" << std::endl;

                    std::getline(std::cin, userIn);
                    userIn = toLowerString(userIn);

                    if (userIn == "back") {
                        break;
                    }
                    else if (userIn == "weapons") {

                    }
                    else if (userIn == "items") {

                        std::cout << std::endl;

                        for (int c = 0; c < currentMerchant->getStackbles().size(); c++) {
                            if (currentMerchant->getStackbles()[c]->getQuantity() <= 0) {
                                continue;
                            }
                            std::cout << currentMerchant->getStackbles()[c]->getName() << string(20 - currentMerchant->getStackbles()[c]->getName().length(), ' ') << currentMerchant->getStackbles()[c]->getQuantity() << std::endl;
                        }

                        std::cout << "\nWhat would you like to buy?" << std::endl;
                        std::cout << "Gold: " << player->getGold() << std::endl;

                        std::getline(std::cin, userIn);
                        userIn = toLowerString(userIn);

                        for (int c = 0; c < currentMerchant->getStackbles().size(); c++) {
                            if (userIn == toLowerString(currentMerchant->getStackbles()[c]->getName()) && currentMerchant->getStackbles()[c]->getQuantity() > 0) {
                                system("CLS");
                                if (player->getGold() >= currentMerchant->getStackbles()[c]->getValue()) {
                                    currentMerchant->getStackbles()[c]->addQuantity(-1);
                                    player->getStackbles()[c]->addQuantity(1);

                                    std::cout << "You bought " << currentMerchant->getStackbles()[c]->getName() << "!" << std::endl;
                                    currentMerchant->greet();

                                    break;
                                }
                                else {
                                    std::cout << "You can't aford that" << std::endl;
                                    break;
                                }

                                
                            }
                        }

                    }



                    //if (questionAsked == false) {
                    //	system("CLS");
                    //	greet();
                    //}
                }
            }
        }
        else {
            currentMerchant = nullptr;
        }
        system("CLS");
        currentRoom->displayRoom();



        // mavigation

        std::cout << "\nwhere would you like to go?\n" << std::endl;
        for (int c = 0; c < currentRoom->getExits().size(); c++) {
            std::cout << " - " << currentRoom->getExits()[c]->getName() << std::endl;
        }
        std::getline(std::cin,userIn);
        userIn = toLowerString(userIn);
        for (int c = 0; c < currentRoom->getExits().size();c++) {
            if (userIn == toLowerString(currentRoom->getExits()[c]->getName())) {
                nextRoom = currentRoom->getExits()[c];
                break;
            }
        }

        system("CLS");
    }
    


}


void linkRooms(Room* room1, Room* room2) {
    room1->addExit(room2);
    room2->addExit(room1);
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


bool yesNoQuestion(string question) {
    string awnser;

    while (true) {
        std::cout << "\n" << question <<" y/n?" << std::endl;
        std::getline(std::cin, awnser);
        awnser = toLowerString(awnser);
        if (awnser == "y") {
            return true;
        }
        else if (awnser == "n") {
            return false;
        }
    }
}