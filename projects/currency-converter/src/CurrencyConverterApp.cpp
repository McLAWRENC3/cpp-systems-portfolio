#include "../include/CurrencyConverterApp.h"
#include "../include/CurrencyService.h"
#include <iostream>
#include <iomanip>

void CurrencyConverterApp::run()
{
    CurrencyService service;

    while (true)
    {
        double amount;
        std::string from;
        std::string to;

        std::cout << "\n===== Currency Converter =====\n";
        std::cout << "Enter amount (0 to exit): ";
        std::cin >> amount;

        if (amount == 0)
            break;

        std::cout << "From currency (e.g USD): ";
        std::cin >> from;

        std::cout << "To currency (e.g ZMW): ";
        std::cin >> to;

        try
        {
            double result = service.convert(amount, from, to);

            std::cout << std::fixed << std::setprecision(4);
            std::cout << amount << " " << from
                      << " = " << result << " " << to << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}