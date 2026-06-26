#include "../include/BMICalculatorApp.h"
#include "../include/BMICalculator.h"
#include <iostream>
#include <iomanip>

void BMICalculatorApp::run()
{
    BMICalculator calculator;
    while (true)
    {
        double weight;
        double height;

        std::cout << "\n===== BMI Calculator ====\n";
        std::cout << "Enter weight in kg (0 to exit): ";
        std::cin >> weight;
        if (weight == 0)
        {
            std::cout << "Exiting BMI Calculator...\n";
            break;
        }

        std::cout << "Enter height in meters (0 to exit): ";
        std::cin >> height;

        try
        {
            double bmi = calculator.calculate(weight, height);
            BMICategory category = calculator.categorize(bmi);
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "\nBMI: " << bmi << "\n";
            std::cout << "Category: "
                      << calculator.categoryToString(category)
                      << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}