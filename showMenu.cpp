#include <sstream>
#include <string>
#include <iostream>
#include <limits>
#include "Enums.h"

// THis function supposed to do all the validation and return already a verified MenuOptions enum type for further actions in main
MenuOptions showMenu()
{
    std::cout << "----- CITY DISTANCE CALCULATOR -----" << '\n'
              << "Chose one of the following options: " << std::endl;
    std::cout << "[0] to start calculation" << '\n'
              << "[1] to quit" << std::endl;
    std::string input;
    int choice;
    bool correctInput{false};
    do
    {
        std::cout << "Your choice: ";
        std::cin >> input;
        std::stringstream ss{input};
        if (ss >> choice && choice > -1 && choice < static_cast<int>(MenuOptions::LAST))
        {
            correctInput = true;
        }
        else
        {
            std::cout << input << " is invalid, retry.\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!correctInput);

    return static_cast<MenuOptions>(choice);
};