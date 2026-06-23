#include "../include/Calculator.h"
#include "../include/Operation.h"
#include <stdexcept>

double Calculator::evaluate(const std::string& expression) {
    auto tokens = parser.tokenize(expression);

    if (tokens.empty()) {
        throw std::runtime_error("Empty expression");
    }

    if (tokens[0].getType() != TokenType::Number) {
        throw std::runtime_error("Expression must start with a number");
    }

    double result = tokens[0].getValue();

    for (size_t i = 1; i < tokens.size(); i += 2) {
        if (i + 1 >= tokens.size()) {
            throw std::runtime_error("Malformed expression");
        }

        char op = tokens[i].getOperator();
        double rhs = tokens[i + 1].getValue();

        auto operation = OperationFactory::create(op);
        result = operation->execute(result, rhs);
    }

    return result;
}