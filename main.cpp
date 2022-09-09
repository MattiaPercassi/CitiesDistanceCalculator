#include "FileReader.h"
#include "City.h"
#include <string>
#include <iostream>
#include <map>
#include "Enums.h"

MenuOptions showMenu();

double calcDistance(const City &, const City &);

int main()
{
    // setup
    FileReader fl{"samplecsv.txt"};
    auto mp = fl.readIntoMap();
    // code
    bool close{false};
    while (!close)
    {
        switch (showMenu())
        {
        case MenuOptions::CALCULATE:
            std::cout << "Calculating distance between " << mp.at("Bergamo").getName() << " and " << mp.at("Milano").getName() <<'\n';
            std::cout << "Distance: " << calcDistance(mp.at("Bergamo"), mp.at("Milano")) << " meters" << std::endl;
            break;
        case MenuOptions::QUIT:
            std::cout << "Quit" << std::endl;
            close = true;
            break;

        default:
            break;
        };
    }

    return 0;
};