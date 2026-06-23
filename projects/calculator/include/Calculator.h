#pragma once
#include<string>
#include "../include/Parser.h"

class Calculator {
private:
	Parser parser;

public:
	double evaluate(const std::string& expression);
};