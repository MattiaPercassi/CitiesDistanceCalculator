#include "FileReader.h"
#include "City.h"
#include <string>
#include <iostream>
#include <vector>
#include "Enums.h"
#include <array>
#include <chrono>

MenuOptions showMenu();
std::array<City, 2> getCities(std::vector<City> &);
double calcDistance(std::array<City, 2> &);

int main()
{
    // setup
    std::chrono::time_point beg = std::chrono::high_resolution_clock::now();
    FileReader fl{"samplecsv.txt"};
    auto vec = fl.readIntoVec();
    std::chrono::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration interval1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - beg);
    std::cout << "For loading file: " << interval1.count() << " ms" << std::endl;
    // code
    bool close{false};
    while (!close)
    {
        switch (showMenu())
        {
        case MenuOptions::CALCULATE:
        {
            auto ct = getCities(vec);
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