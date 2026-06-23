#pragma once
#include <string>

enum class TokenType {
    Number,
    Operator
};

class Token {
private:
    TokenType type;
    double value;
    char op;

public:
    Token(double num)
        : type(TokenType::Number), value(num), op('\0') {
    }

    Token(char oper)
        : type(TokenType::Operator), value(0), op(oper) {
    }

    TokenType getType() const { return type; }
    double getValue() const { return value; }
    char getOperator() const { return op; }
};