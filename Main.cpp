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
#include "Weapon.h"
#include "Merchant.h"

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

    std::cout << "--------------------" << std::endl;
    std::cout << "welcome to the game!" << std::endl;
    std::cout << "--------------------\n" << std::endl;
    std::cout << "How to play:" << std::endl;
    std::cout << "type in what you want to do, type \"back\" if you want to back out of any menus (not navigation)" << std::endl;
    std::cout << "\n pro tip:\n hit the up arrow on your keyboard to use your last command!\n\n" << std::endl;

    if (yesNoQuestion("Read to play?") == false) {
        return 0;
    }


    system("CLS");


    //player init
    player = new Player();
    player->addWeapon(new Weapon("sword", 10, 10, &statDefs[1]));
    player->addWeapon(new Weapon("gun", 20, 50, &statDefs[0]));
    player->getStackbles()[0]->addQuantity(1);
    player->getStackbles()[1]->addQuantity(1);
    player->getStackbles()[2]->addQuantity(1);

    //world init
    rooms.push_back(new Room("Dark Room", "There is a light in another room"));
    
    rooms.push_back(new Room("Lit Room", "The light is dim but you can see two paths in front of you."));
    
    rooms.push_back(new Room("Stairway", "The steps are steep, but you climb to a wooden hatch"));
    
    rooms.push_back(new Room("Kitchen", "an old kitchen, cold and empty.", new Enemy("goblin", 50, 20, 10, 110, 60)));

    rooms.push_back(new Room("Pantry", "A small empty pantry with an old man hiding in it.", new Npc("Old Man", "A scared old man hiding in a pantry")));
    rooms[4]->getNpc()->addDialgue(new Dialogue("What are you doing here?", "Hiding from that thing. But you saved me, thanks you!"));
    rooms[4]->getNpc()->addDialgue(new Dialogue("Do you know how to get out of here?", "Go back the way you came and take the stairs."));

    rooms.push_back(new Room("Grassy Plain", "an open patch of land with a wooden hatch on the ground. You see a tent in the distance set up next to a cart full of goods."));

    rooms.push_back(new Room("Merchant tent", "The camp of a traveling merchant", new Merchant("Traveling Merchant", "His eyes glisten at the sight of a potential customer.")));
    rooms[6]->getMerchant()->getStackbles()[0]->addQuantity(3);
    rooms[6]->getMerchant()->getStackbles()[1]->addQuantity(1);
    rooms[6]->getMerchant()->getStackbles()[3]->addQuantity(1);
    rooms[6]->getMerchant()->addWeapon(new Weapon("Silver Sword", 50, 100, &statDefs[1]));
    rooms[6]->getMerchant()->addWeapon(new Weapon("Rifle", 70, 200, &statDefs[0]));

    rooms.push_back(new Room("Evil looking Building", " Your outside of a decidedly evil looking building with a frantic game deveoper standing outside.", new Npc("Game Developer", "He looks tired, frustrated, and frantic")));
    rooms[7]->getNpc()->addDialgue(new Dialogue("Who are you?", "Not important! The fact is that this assignment is due in like 30 minutes and this game needs an ending. so get in there and kill something big or whatever"));
    rooms[7]->getNpc()->addDialgue(new Dialogue("What is this place?", "it's whatever you want it to be man... I have so little time left I had to break the fourth wall just to get this thing finished!"));
    rooms[7]->getNpc()->addDialgue(new Dialogue("Why did I wake up in a dark room?", "Because it was the first thing I thought of. What you want a story? HA! Budy I don't even have time to balance the combat in this game let alone add a story. At this point this is basically a glorified tech demo. But it works!"));

    rooms.push_back(new Room("Boss Room", "Imagine a final boss room, ya thats basically it.", new Enemy("My Own Ambition", 500, 70, 200, 200, 10)));
    rooms.push_back(new Room("The End", "The end of the game."));
    

    linkRooms(rooms[0], rooms[1]);
    linkRooms(rooms[1], rooms[2]);
    linkRooms(rooms[1], rooms[3]);
    linkRooms(rooms[2], rooms[5]);
    linkRooms(rooms[3], rooms[4]);
    linkRooms(rooms[5], rooms[6]);
    linkRooms(rooms[5], rooms[7]);
    linkRooms(rooms[7], rooms[8]);
    linkRooms(rooms[8], rooms[9]);
    
    //init pointers
    currentRoom = rooms[0];
    nextRoom = nullptr;
    currentEnemy = nullptr;
    currentNpc = nullptr;
    lastRoom = nullptr;

    
    
    // --- game loop --- //
    while (true) {

        
        // --- Changing rooms --- //
        if (nextRoom != nullptr) {
            lastRoom = currentRoom;
            currentRoom = nextRoom;
            nextRoom = nullptr;
        }

        if (currentRoom == rooms[9]) {
            system("CLS");
            std::cout << "--------------" << std::endl;
            std::cout << " - YOU WON! - " << std::endl;
            std::cout << "--------------" << std::endl;
            return 0;
        }



        // --- Combat header (only meant to show up once)--- //
        if (currentRoom->getEnemy() != nullptr) {
            //system("CLS");
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

        // --- Combat Loop --- //
        while (currentEnemy != nullptr) {
            
            // use item, flee, use weapon,

            std::cout << "\nYour health: " << player->getHealth() << "/" << player->getMaxHealth() << "         " << currentEnemy->getName() << " health: " << currentEnemy->getHealth() << "/" << currentEnemy->getMaxHealth() << std::endl;
            std::cout << "\nWhat do you want to do?\n" << std::endl;
            std::cout << "-Use Item\n-Use Weapon\n-Flee\n" << std::endl;
               
            
            std::getline(std::cin, userIn);
            userIn = toLowerString(userIn);

            // --- using item --- //
            if (userIn == "use item") {

                //print items
                for (int c = 0; c < player->getStackbles().size(); c++) {
                    if (player->getStackbles()[c]->getQuantity() <= 0) {
                        continue;
                    }
                    std::cout << player->getStackbles()[c]->getName() << string(20 - player->getStackbles()[c]->getName().length(), ' ') << player->getStackbles()[c]->getQuantity() << std::endl;
                }

                // get item
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
                        if (weaponChoice == toLowerString(player->getWeapons()[c]->getName())) {

                            int playerDmg = player->getDamage(player->getWeapons()[c]);
                            currentEnemy->takeDamage(playerDmg);

                            player->clearBuffs(false);

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
            
            if (yesNoQuestion(currentMerchant->getName() + " is here. Would you like to buy from them?")) {


                system("CLS");
                


                while (true) {
                    currentMerchant->greet();
                    std::cout << "\nWhat kind of Item's would you like to buy?\nWeapons\nItems" << std::endl;

                    std::getline(std::cin, userIn);
                    userIn = toLowerString(userIn);

                    if (userIn == "back") {
                        break;
                    }
                    else if (userIn == "weapons") {

                        // print merchant weapons
                        std::cout << "\nWeapon              dmg\tvalue" << std::endl;
                        for (int c = 0; c < currentMerchant->getWeapons().size(); c++) {
                            std::cout << currentMerchant->getWeapons()[c]->getName() << string(20 - currentMerchant->getWeapons()[c]->getName().size(), ' ') << currentMerchant->getWeapons()[c]->getDamage() << "\t" << currentMerchant->getWeapons()[c]->getValue() << std::endl;

                        }
                        // buy loop
                        std::cout << "\nWhat would you like to buy?" << std::endl;
                        std::cout << "Gold: " << player->getGold() << std::endl;

                        std::getline(std::cin, userIn);
                        userIn = toLowerString(userIn);
                        bool weaponPurchaseAtempted = false;
                        for (int c = 0; c < currentMerchant->getWeapons().size(); c++) {
                            if (userIn == toLowerString(currentMerchant->getWeapons()[c]->getName())) {
                                system("CLS");
                                if (player->getGold() >= currentMerchant->getWeapons()[c]->getValue()) {

                                    std::cout << "\nyou bought the " << currentMerchant->getWeapons()[c]->getName() << "!\n" << std::endl;
                                    player->addGold(currentMerchant->getWeapons()[c]->getValue() * -1);
                                    player->addWeapon(currentMerchant->getWeapons()[c]);
                                    currentMerchant->removeWeapon(c);
                                    
                                    weaponPurchaseAtempted = true;
                                    break;
                                }
                                else {
                                    std::cout << "You can't afford that" << std::endl;
                                    break;
                                }

                                
                            }
                        }
                        if (weaponPurchaseAtempted == false) {
                            system("CLS");
                        }
                        

                    }
                    else if (userIn == "items") {

                        std::cout << std::endl;

                        //print merchant items
                        std::cout << "item                value\tmerchant\tyou" << std::endl;
                        for (int c = 0; c < currentMerchant->getStackbles().size(); c++) {
                            if (currentMerchant->getStackbles()[c]->getQuantity() <= 0 && player->getStackbles()[c]->getQuantity() <= 0) {
                                continue;
                            }
                            
                            std::cout << currentMerchant->getStackbles()[c]->getName() << string(20 - currentMerchant->getStackbles()[c]->getName().length(), ' ') << currentMerchant->getStackbles()[c]->getValue() << "\t\t" << currentMerchant->getStackbles()[c]->getQuantity();
                            std::cout << "\t\t" << player->getStackbles()[c]->getQuantity() << std::endl;
                        }

                        // buy loop
                        std::cout << "\nWhat would you like to buy?" << std::endl;
                        std::cout << "Gold: " << player->getGold() << std::endl;

                        std::getline(std::cin, userIn);
                        userIn = toLowerString(userIn);
                        bool itemPurchaseAtempted = false;
                        for (int c = 0; c < currentMerchant->getStackbles().size(); c++) {
                            if (userIn == toLowerString(currentMerchant->getStackbles()[c]->getName()) && currentMerchant->getStackbles()[c]->getQuantity() > 0) {
                                system("CLS");
                                if (player->getGold() >= currentMerchant->getStackbles()[c]->getValue()) {
                                    currentMerchant->getStackbles()[c]->addQuantity(-1);
                                    player->getStackbles()[c]->addQuantity(1);
                                    player->addGold(currentMerchant->getStackbles()[c]->getValue() * -1);
                                    itemPurchaseAtempted = true;
                                    std::cout << "\nYou bought " << currentMerchant->getStackbles()[c]->getName() << "!\n" << std::endl;

                                    break;
                                }
                                else if (userIn == toLowerString(currentMerchant->getStackbles()[c]->getName()) && currentMerchant->getStackbles()[c]->getQuantity() <= 0) {
                                    std::cout << "Out of Stock" << std::endl;
                                    break;
                                }
                                else {
                                    std::cout << "You can't afford that" << std::endl;
                                    break;
                                }
                            }
                        }
                        if (itemPurchaseAtempted = false) {
                            system("CLS");
                        }
                        

                    }


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

        player->clearBuffs(true);

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