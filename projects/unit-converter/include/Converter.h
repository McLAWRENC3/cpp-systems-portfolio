#pragma once
#include <string>

// Abstract base class for all converter types
class Converter
{
public:
    virtual ~Converter() = default;

    // Convert value from one unit to another
    virtual double convert(double value,
                           const std::string &fromUnit,
                           const std::string &toUnit) const = 0;
};