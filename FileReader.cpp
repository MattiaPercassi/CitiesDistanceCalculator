#include "FileReader.h"
#include <string>
#include <fstream>

FileReader::FileReader(std::string filepath) : inputFile{filepath} {};
FileReader::FileReader() : FileReader(""){};