#include "Player.h"

Player::Player() : Agent(100) {

    m_Level = 0;
    m_Exp = 0;
    m_skillPoints = 2;

    m_Fortitude = 1;
    m_Fortune = 1;
    m_Strength = 1;
    m_Marksmanship = 1;

    string intro = "Create your Character!";
    std::cout << string(intro.size(), '-') << std::endl;
    std::cout << intro << std::endl;
    std::cout << string(intro.size(), '-') << std::endl;


    // --- Name --- //
    string nameTemp;
    while (true) {
        std::cout << "\n Name:\t";

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


    //--- get player stats ---//
    while (m_skillPoints > 0) {

        std::cout << "You are currently level " << m_Level << " and have " << m_skillPoints << " skillpoints." << std::endl;
        std::cout << "choose a stat to upgrade" << std::endl;
        printStats();
        string specTemp = "";
        while (true) {
            std::cout << "Type the stat you would like to spec into:" << std::endl;
            std::cin >> specTemp;

            if (specTemp == "marksmanship") {
                m_Marksmanship++;
                m_Level++;
                m_skillPoints--;
                break;
            }
            else if (specTemp == "strength") {
                m_Strength++;
                m_Level++;
                m_skillPoints--;
                break;
            }
            else if (specTemp == "fortitude") {
                m_Fortitude++;
                m_Level++;
                m_skillPoints--;
                break;
            }
            else if (specTemp == "fortune") {
                m_Fortune++;
                m_Level++;
                m_skillPoints--;
                break;
            }
        }
        
    }
    

    system("CLS");

}

void Player::printStats() {
    std::cout << "Marksmanship: " << m_Marksmanship << std::endl;
    std::cout << "Strength:     " << m_Strength << std::endl;
    std::cout << "Fortitude:    " << m_Fortitude << std::endl;
    std::cout << "Fortune:      " << m_Fortune << std::endl;
}