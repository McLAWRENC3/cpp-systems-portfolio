#include "../include/Calculator.h"
#include "../include/OperationFactory.h"
#include <iostream>
#include <iomanip>

void Calculator::run()
{
    while (true)
    {
        std::string op;

        std::cout << "\nScientific Calculator\n";
        std::cout << "Operations:\n";
        std::cout << "add sub mul div sin cos tan log ln pow sqrt fact\n";
        std::cout << "Enter operation (or exit): ";

        std::cin >> op;

        if (op == "exit")
            break;

        try
        {
            auto operation = OperationFactory::create(op);

            double a, b = 0;

            std::cout << "Enter first number: ";
            std::cin >> a;

            // Binary operations need second operand
            if (op == "add" || op == "sub" || op == "mul" ||
                op == "div" || op == "pow")
            {
                std::cout << "Enter second number: ";
                std::cin >> b;
            }

            double result = operation->execute(a, b);

            std::cout << std::fixed << std::setprecision(6);
            std::cout << "Result: " << result << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}