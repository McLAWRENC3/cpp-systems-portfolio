#pragma once
#include "Converter.h"
#include <unordered_map>
#include <stdexcept>

// ================= LENGTH CONVERTER =================
// Base unit: meter
class LengthConverter : public Converter
{
private:
    const std::unordered_map<std::string, double> toMeters = {
        {"mm", 0.001},
        {"cm", 0.01},
        {"m", 1.0},
        {"km", 1000.0},
        {"in", 0.0254},
        {"ft", 0.3048}};

public:
    double convert(double value,
                   const std::string &fromUnit,
                   const std::string &toUnit) const override
    {
        if (!toMeters.count(fromUnit) || !toMeters.count(toUnit))
            throw std::runtime_error("Invalid length unit");

        double meters = value * toMeters.at(fromUnit);
        return meters / toMeters.at(toUnit);
    }
};

// ================= WEIGHT CONVERTER =================
// Base unit: kilogram
class WeightConverter : public Converter
{
private:
    const std::unordered_map<std::string, double> toKg = {
        {"g", 0.001},
        {"kg", 1.0},
        {"lb", 0.453592},
        {"oz", 0.0283495}};

public:
    double convert(double value,
                   const std::string &fromUnit,
                   const std::string &toUnit) const override
    {
        if (!toKg.count(fromUnit) || !toKg.count(toUnit))
            throw std::runtime_error("Invalid weight unit");

        double kg = value * toKg.at(fromUnit);
        return kg / toKg.at(toUnit);
    }
};

// ================= TEMPERATURE CONVERTER =================
class TemperatureConverter : public Converter
{
public:
    double convert(double value,
                   const std::string &fromUnit,
                   const std::string &toUnit) const override
    {

        if (fromUnit == toUnit)
            return value;

        // Convert source to Celsius
        double celsius;

        if (fromUnit == "C")
            celsius = value;
        else if (fromUnit == "F")
            celsius = (value - 32.0) * 5.0 / 9.0;
        else if (fromUnit == "K")
            celsius = value - 273.15;
        else
            throw std::runtime_error("Invalid temperature unit");

        // Convert Celsius to target
        if (toUnit == "C")
            return celsius;
        else if (toUnit == "F")
            return (celsius * 9.0 / 5.0) + 32.0;
        else if (toUnit == "K")
            return celsius + 273.15;

        throw std::runtime_error("Invalid temperature unit");
    }
};