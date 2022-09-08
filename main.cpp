#include "FileReader.h"
#include "City.h"
#include <string>
#include <iostream>

int main()
{
    City c1{"Bergamo", "Italia", 45.42, 09.40};
    City c2{"Milano", "Italia", 45.28, 09.11};
    std::cout << std::boolalpha;
    std::cout << c1 << c2 << (c1 < c2);

    return 0;
};