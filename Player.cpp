#include "Player.h"

Player::Player() : Agent(100) {

    string intro = "Create your Character!";
    std::cout << string(intro.size(), '-') << std::endl;
    std::cout << intro << std::endl;
    std::cout << string(intro.size(), '-') << std::endl;


    // --- Name --- //
    string nameTemp;
    while (true) {
        std::cout << "\n What is your name:\t";

        //std::getline(std::cin, nameTemp); // this line was being weird on the second time the program loops
        std::cin >> nameTemp;
        if (nameTemp != "" && nameTemp.size() < 20) {
            m_Name = nameTemp;
            break;
        }
        else {
            std::cout << "\n Invalid Name\n" << std::endl;
        }
    }

    system("CLS");


    std::cout << string(intro.size(), '-') << std::endl;
    std::cout << intro << std::endl;
    std::cout << string(intro.size(), '-') << std::endl;


    // --- Class --- //
    bool validClass = false;
    string classTemp;
    std::cout << "\nAnd who are you " << m_Name << "?" << std::endl;
    int classOptionSpacing = 15;
    std::cout << classNames[0] << string(classOptionSpacing - classNames[0].length(), ' ') << "A true marksman! just don't miss..." << std::endl;
    std::cout << classNames[1] << string(classOptionSpacing - classNames[1].length(), ' ') << "You prefer a more hands on aproach." << std::endl;
    std::cout << classNames[2] << string(classOptionSpacing - classNames[2].length(), ' ') << "Your enemies will wish they brought more bullets." << std::endl;
    std::cout << classNames[3] << string(classOptionSpacing - classNames[3].length(), ' ') << "Your not particularly good at anything, but that hasn't stopped you so far." << std::endl;
    while (validClass == false) {
        

        std::cin >> classTemp;
        for (int c = 0; c < classNamesLower->size(); c++) {
            if (classTemp == classNamesLower[c]) {
                m_Class = &classNamesLower[c];
                validClass = true;
                break;
            }
        }

    }

    if (*m_Class == classNamesLower[0]) {
        std::cout << "STATS APLIED" << std::endl;
        m_Level = 7;
        m_Marksmanship = 3;
        m_Strength = 2;
        m_Fortitude = 1;
        m_Fortune = 1;
    }
    else if (*m_Class == classNamesLower[1]) {
        m_Level = 7;
        m_Marksmanship = 1;
        m_Strength = 3;
        m_Fortitude = 2;
        m_Fortune = 1;
    }
    else if (*m_Class == classNamesLower[2]) {
        m_Level = 7;
        m_Marksmanship = 1;
        m_Strength = 1;
        m_Fortitude = 3;
        m_Fortune = 2;
    }
    else if (*m_Class == classNamesLower[3]) {
        m_Level = 7;
        m_Marksmanship = 1;
        m_Strength = 1;
        m_Fortitude = 1;
        m_Fortune = 4;
    }
    else {
        std::cout << "STATS NOT APLIED" << std::endl;
    }

    system("CLS");

    //--- get player Class ---//
    levelup();

}


void Player::levelup() {
    while (m_skillPoints > 0) {

        std::cout << "\nYou are currently a level " << m_Level << " " << *m_Class << " and have " << m_skillPoints << " skillpoints." << std::endl;
        std::cout << "\nchoose a stat to upgrade" << std::endl;
        printStats();
        string specTemp = "";
        while (true) {
            std::cout << "\nType the stat you would like to spec into:" << std::endl;
            std::cin >> specTemp;

            if (specTemp == statDefsLower[0]) {
                m_Marksmanship++;
                m_Level++;
                m_skillPoints--;
                system("CLS");
                std::cout << "\nYou have upgraded your " << statDefs[0] << " to " << m_Marksmanship << ".\n" << std::endl;
                break;
            }
            else if (specTemp == statDefsLower[1]) {
                m_Strength++;
                m_Level++;
                m_skillPoints--;
                system("CLS");
                std::cout << "\nYou have upgraded your " << statDefs[1] << " to " << m_Strength << ".\n" << std::endl;
                break;
            }
            else if (specTemp == statDefsLower[2]) {
                m_Fortitude++;
                m_Level++;
                m_skillPoints--;
                system("CLS");
                std::cout << "\nYou have upgraded your " << statDefs[2] << " to " << m_Fortitude << ".\n" << std::endl;
                break;
            }
            else if (specTemp == statDefsLower[3]) {
                m_Fortune++;
                m_Level++;
                m_skillPoints--;
                system("CLS");
                std::cout << "\nYou have upgraded your " << statDefs[3] << " to " << m_Fortune << "." << std::endl;
                break;
            }
        }



    }
    system("CLS");
    std::cin.ignore();
}


void Player::printStats() {
    std::cout << statDefs[0] << ": " << m_Marksmanship << std::endl;
    std::cout << statDefs[1] << ":     " << m_Strength << std::endl;
    std::cout << statDefs[2] << ":    " << m_Fortitude << std::endl;
    std::cout << statDefs[3] << ":      " << m_Fortune << std::endl;
}

void Player::addWeapon(Weapon* newWeapon) {
    m_Weapons.push_back(newWeapon);
}

vector<Weapon*> Player::getWeapons() const {
    return m_Weapons;
}


int Player::getDamage(Weapon* held) {

    if (*held->getRelatedStats() == statDefs[0]) {
        return held->getDamage() * m_Marksmanship;
    } 
    else if (*held->getRelatedStats() == statDefs[1]) {
        return held->getDamage() * m_Strength;
    }
    else if (*held->getRelatedStats() == statDefs[2]) {
        return held->getDamage();
    }
    else if (*held->getRelatedStats() == statDefs[3]) {
        return held->getDamage();
    }
    else {
        std::cout << "THAT IS NOT A VALID STAT" << std::endl;
        return 0;
    }

}

