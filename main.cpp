#include "FileReader.h"
#include "City.h"
#include <string>
#include <iostream>
#include <map>

int main()
{
    // setup
    FileReader fl{"samplecsv.txt"};
    auto mp = fl.readIntoMap();
    // code

    return 0;
};