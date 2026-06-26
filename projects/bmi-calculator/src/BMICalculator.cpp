#include "../include/BMICalculator.h"
#include <stdexcept>

// Calculate BMI using standard formula:
// BMI = weight / (height^2)
double BMICalculator::calculate(double weightKg, double heightMeters) const
{
    if (weightKg <= 0)
    {
        throw std::invalid_argument("Weight must be greater than zero.");
    }

    if (heightMeters <= 0)
    {
        throw std::invalid_argument("Height must be greater than zero.");
    }

    return weightKg / (heightMeters * heightMeters);
}

// Categorize BMI using WHO ranges
BMICategory BMICalculator::categorize(double bmi) const
{
    if (bmi < 18.5)
    {
        return BMICategory::Underweight;
    }
    else if (bmi < 25.0)
    {
        return BMICategory::Normal;
    }
    else if (bmi < 30.0)
    {
        return BMICategory::Overweight;
    }

    return BMICategory::Obese;
}

// Convert enum category into readable text
std::string BMICalculator::categoryToString(BMICategory category) const
{
    switch (category)
    {
    case BMICategory::Underweight:
        return "Underweight";

    case BMICategory::Normal:
        return "Normal Weight";

    case BMICategory::Overweight:
        return "Overweight";

    case BMICategory::Obese:
        return "Obese";

    default:
        return "Unknown";
    }
}