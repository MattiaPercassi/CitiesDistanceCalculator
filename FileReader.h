#ifndef _FILEREADER_H_
#define _FILEREADER_H_

#include <string>
#include <fstream>
#include <map>

class FileReader
{
protected:
    std::ifstream inputFile;

public:
    FileReader(std::string);
    FileReader();

    // This fileReader is specific for creating a map for this specific application
    // std::map<std::string, City> readIntoMap(std::string);
};

#endif