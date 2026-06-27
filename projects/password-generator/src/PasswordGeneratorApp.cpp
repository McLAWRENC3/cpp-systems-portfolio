#include "../include/PasswordGeneratorApp.h"
#include "../include/PasswordGenerator.h"
#include <iostream>

void PasswordGeneratorApp::run()
{
    PasswordGenerator generator;

    while (true)
    {
        int length;
        char lower, upper, digits, symbols;

        std::cout << "\n===== Password Generator =====\n";
        std::cout << "Enter password length (0 to exit): ";
        std::cin >> length;

        if (length == 0)
        {
            std::cout << "Exiting...\n";
            break;
        }

        std::cout << "Include lowercase? (y/n): ";
        std::cin >> lower;

        std::cout << "Include uppercase? (y/n): ";
        std::cin >> upper;

        std::cout << "Include digits? (y/n): ";
        std::cin >> digits;

        std::cout << "Include symbols? (y/n): ";
        std::cin >> symbols;

        try
        {
            std::string password = generator.generate(
                length,
                lower == 'y' || lower == 'Y',
                upper == 'y' || upper == 'Y',
                digits == 'y' || digits == 'Y',
                symbols == 'y' || symbols == 'Y');

            std::cout << "\nGenerated Password:\n";
            std::cout << password << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}