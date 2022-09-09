#include <array>
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <map>
#include "City.h"

std::array<City, 2> getCities(std::map<std::string, City> &mp)
{
    std::array<City, 2> arr;
    std::string input;
    bool flag1{false};
    while (!flag1)
    {
        std::cout << "What is the first city? ";
        std::cin >> input;
        if (mp.find(input) != mp.end())
        {
            arr.at(0) = mp.at(input);
            std::cout << "First city: " << input << std::endl;
            flag1 = true;
        }
        else
        {
            std::cout << input << " is invalid input, retry\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };
    std::string input2;
    bool flag2{false};
    while (!flag2)
    {
        std::cout << "What is the second city? ";
        std::cin >> input2;
        if (mp.find(input2) != mp.end() && input2 != input)
        {
            arr.at(1) = mp.at(input2);
            std::cout << "Second city: " << input2 << std::endl;
            flag2 = true;
        }
        else
        {
            std::cout << input2 << " is invalid input, retry\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return arr;
};