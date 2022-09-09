#include "FileReader.h"
#include "City.h"
#include <string>
#include <iostream>
#include <map>

int showMenu();

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
        case 1:
            std::cout << "Choice 1" << std::endl;
            close = true;
            break;

        default:
            break;
        };
    }

    return 0;
};