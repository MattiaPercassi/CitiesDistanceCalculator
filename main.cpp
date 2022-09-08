#include "FileReader.h"
#include "City.h"
#include <string>
#include <iostream>
#include <map>

int main()
{
    City c1{"Bergamo", "Italia", 45.42, 09.40};
    City c2{"Milano", "Italia", 45.28, 09.11};
    std::cout << std::boolalpha;
    std::cout << c1 << c2 << (c1 < c2) << std::endl;
    std::map<std::string, City> mp;
    mp[c1.getName()] = c1;
    std::string search = "Bergamo";
    auto it = mp.find(search);
    if (it != mp.end())
    {
        std::cout << mp.at(search);
    }
    return 0;
};