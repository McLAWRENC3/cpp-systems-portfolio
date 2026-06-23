#pragma once
#include <vector>
#include <string>
#include "Token.h"

class Parser {
public:
    std::vector<Token> tokenize(const std::string& expression);
};