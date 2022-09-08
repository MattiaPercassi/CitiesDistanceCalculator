#include "City.h"
#include <iostream>
#include <string>
#include <iomanip>

City::City(std::string nm, std::string ct, double lat, double lon) : name{nm}, country{ct}, latitude{lat}, longitude{lon} {};
City::City(const City &src) : City(src.name, src.country, src.latitude, src.longitude){};

std::string City::getName()
{
    return name;
};
double City::getLat()
{
    return latitude;
};
double City::getLon()
{
    return longitude;
};

std::ostream &operator<<(std::ostream &os, City &rhs)
{
    os << rhs.name << " (" << rhs.country << ")" << '\n'
       << std::setw(13) << std::left << "Latitude:" << rhs.latitude << '\n'
       << std::setw(13) << std::left << "Longitude:" << rhs.longitude << std::endl;
    return os;
};

bool operator==(City &lhs, City &rhs)
{
    return (lhs.name == rhs.name && lhs.country == rhs.country);
};

bool operator<(City &lhs, City &rhs)
{
    if (lhs.name != rhs.name)
        return lhs.name < rhs.name;
    else
        return lhs.country < rhs.country;
};
