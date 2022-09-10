#include <array>
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "City.h"
#include <chrono>

std::array<City, 2> getCities(std::vector<City> &vec)
{
    std::array<City, 2> arr;
    std::string input;
    bool flag1{false};
    while (!flag1)
    {
        std::cout << "What is the first city? ";
        std::getline(std::cin, input);
        std::chrono::time_point beg = std::chrono::high_resolution_clock::now();
        if (std::find(vec.begin(), vec.end(), input) != vec.end())
        {
            arr.at(0) = *(std::find(vec.begin(), vec.end(), input));
            std::cout << "First city: " << input << std::endl;
            flag1 = true;
        }
        else
        {
            std::cout << input << " is invalid input, retry\n";
        }
        std::chrono::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration interval = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
        std::cout << "To check this result took: " << interval.count() << " us" << std::endl;
        // since we collect input with getline we do not need to ignore the buffer as no data will be there
        //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };
    std::string input2;
    bool flag2{false};
    while (!flag2)
    {
        std::cout << "What is the second city? ";
        std::getline(std::cin, input2);
        std::chrono::time_point beg = std::chrono::high_resolution_clock::now();
        if (std::find(vec.begin(), vec.end(), input2) != vec.end() && input2 != input)
        {
            arr.at(1) = *(std::find(vec.begin(), vec.end(), input2));
            std::cout << "Second city: " << input2 << std::endl;
            flag2 = true;
        }
        else
        {
            std::cout << input2 << " is invalid input, retry\n";
        }
        std::chrono::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration interval = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
        std::cout << "To check this result took: " << interval.count() << " us" << std::endl;
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return arr;
};