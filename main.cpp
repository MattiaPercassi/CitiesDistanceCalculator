#include "FileReader.h"
#include "City.h"
#include <string>
#include <iostream>
#include <map>
#include "Enums.h"
#include <array>

MenuOptions showMenu();
std::array<City, 2> getCities(std::map<std::string, City> &);
double calcDistance(std::array<City, 2> &);

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
        {
            auto ct = getCities(mp);
            std::cout << "The distance between " << ct.at(0).getName() << " and " << ct.at(1).getName() << " is " << calcDistance(ct) / 1000 << " km" << std::endl;
            break;
        }

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