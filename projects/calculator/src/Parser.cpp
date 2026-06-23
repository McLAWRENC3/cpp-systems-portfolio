#include "../include/Parser.h"
#include <cctype>
#include <stdexcept>

std::vector<Token> Parser::tokenize(const std::string& expression) {
    std::vector<Token> tokens;
    std::string numberBuffer;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (std::isspace(c)) {
            continue;
        }

        if (std::isdigit(c) || c == '.') {
            numberBuffer.clear();

            while (i < expression.size() &&
                (std::isdigit(expression[i]) || expression[i] == '.')) {
                numberBuffer += expression[i];
                i++;
            }

            i--;
            tokens.emplace_back(std::stod(numberBuffer));
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            tokens.emplace_back(c);
        }
        else {
            throw std::runtime_error("Invalid character in expression");
        }
    }

    return tokens;
}