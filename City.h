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
    // default ctor needed for map creation
    City(){};
    City(const City &);
    std::string getName() const;
    double getLat() const;
    double getLon() const;
};

#endif