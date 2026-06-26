#pragma once
#include <string>

// Strongly typed BMI categories
enum class BMICategory
{
    Underweight,
    Normal,
    Overweight,
    Obese
};

// Handles BMI computation and classification
class BMICalculator
{
public:
    double calculate(double weightKg, double heightMeters) const;
    BMICategory categorize(double bmi) const;
    std::string categoryToString(BMICategory category) const;
};