#ifndef _FILEREADER_H_
#define _FILEREADER_H_

#include <string>
#include <fstream>
#include <vector>
#include "City.h"

class FileReader
{
protected:
    std::string inputFile;

public:
    FileReader(std::string);
    FileReader();

    // This fileReader is specific for creating a map for this specific application
    std::vector<City> readIntoVec();
};

#endif