#include <iostream>
#include "../include/Calculator.h"
int main()
{
	Calculator calculator;
	std::string expression;
	std::cout << "=== C++ Calculator ===\n";
	std::cout << "Type 'exit' to quit\n";
	while (true)
	{
		std::cout << "\nEnter expression: ";
		std::getline(std::cin, expression);
		if (expression == "exit")
		{
			break;
		}
		try
		{
			double result = calculator.evaluate(expression);
			std::cout << "Result: " << result << "\n";
		}
		catch (const std::exception &ex)
		{
			std::cout << "Error: " << ex.what() << "\n";
		}
	}
	return 0;
}