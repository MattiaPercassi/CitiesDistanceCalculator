#include "FileReader.h"
#include "City.h"
#include <string>
#include <map>
#include <fstream>

FileReader::FileReader(std::string filepath) : inputFile{filepath} {};
FileReader::FileReader() : FileReader(""){};

std::map<std::string, City> FileReader::readIntoMap()
{
    std::map<std::string, City> mp;
    std::ifstream ifile{inputFile};
    if (!ifile)
        return mp;
    std::string line;
    std::string nm;
    std::string ct;
    std::string lat;
    std::string lon;
    const char separationChar = ',';
    while (std::getline(ifile, line))
    {
        size_t iterator{0};
        iterator = line.find(separationChar);
        nm = line.substr(0, iterator);
        line = line.substr(iterator + 1);

        iterator = line.find(separationChar);
        ct = line.substr(0, iterator);
        line = line.substr(iterator + 1);

        iterator = line.find(separationChar);
        lat = line.substr(0, iterator);
        line = line.substr(iterator + 1);

        lon = line;
        mp[nm] = City{nm, ct, std::stod(lat), std::stod(lon)};
    };
    ifile.close();
    return mp;
};