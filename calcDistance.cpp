#include <cmath>
#include <array>
#include "City.h"

double calcDistance(std::array<City, 2> &ct)
{
    constexpr double pi = 3.14159;
    constexpr double earthRadius = 6371000; //[m]
    double lat1 = ct.at(0).getLat();
    double lat2 = ct.at(1).getLat();
    // convert to radiants
    lat1 = lat1 * pi / 180;
    lat2 = lat2 * pi / 180;
    const double dlat = (lat2 - lat1) * pi / 180;
    const double dlon = (ct.at(1).getLon() - ct.at(0).getLon()) * pi / 180;
    const double a = std::sin(dlat / 2) * std::sin(dlat / 2) + std::cos(lat1) * std::cos(lat2) * std::sin(dlon / 2) * std::sin(dlon / 2);
    const double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return earthRadius * c;
};