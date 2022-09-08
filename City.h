#ifndef _CITY_H_
#define _CITY_H_

#include <string>
#include <iostream>

class City
{

    friend std::ostream &operator<<(std::ostream &, City &);
    friend bool operator==(City &, City &);
    friend bool operator<(City &, City &);

protected:
    std::string name;
    std::string country;
    double latitude;
    double longitude;

public:
    City(std::string, std::string, double, double);
    std::string getName();
    double getLat();
    double getLon();
};

#endif