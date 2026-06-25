#include "../include/UnitConverterApp.h"
#include "../include/Converters.h"
#include <iostream>
#include <iomanip>
#include <memory>

void UnitConverterApp::run()
{
    while (true)
    {
        int choice;
        double value;
        std::string fromUnit;
        std::string toUnit;

        std::cout << "\n==== Unit Convert ====\n";
        std::cout << "1. Length\n";
        std::cout << "2. Weight\n";
        std::cout << "3. Temperature\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose category";

        std::cin >> choice;

        if (choice == 4)
            break;
        std::unique_ptr<Converter> converter;
        switch (choice)
        {
        case 1:
            converter = std::make_unique<LengthConverter>();
            std::cout << "Units: mm cm m km in ft\n";
            break;
        case 2:
            converter = std::make_unique<WeightConverter>();
            std::cout << "Units: g kg lb oz \n";
            break;
        case 3:
            converter = std::make_unique<TemperatureConverter>();
            std::cout << "Units: C F K\n";
            break;
        default:
            std::cout << "Invalid choice\n";
            continue;
        }
        std::cout << "Enter value: ";
        std::cin >> value;

        std::cout << "From unit: ";
        std::cin >> fromUnit;

        std::cout << "To unit: ";
        std::cin >> toUnit;

        try
        {
            double result = converter->convert(value, fromUnit, toUnit);
            std::cout << std::fixed << std::setprecision(6);
            std::cout << "Result: " << result << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}
