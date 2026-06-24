#include "../include/OperationFactory.h"
#include "../include/Operations.h"
#include <stdexcept>

std::unique_ptr<Operation> OperationFactory::create(const std::string &op)
{
    if (op == "add")
        return std::make_unique<AddOperation>();
    if (op == "sub")
        return std::make_unique<SubtractOperation>();
    if (op == "mul")
        return std::make_unique<MultiplyOperation>();
    if (op == "div")
        return std::make_unique<DivideOperation>();
    if (op == "sin")
        return std::make_unique<SinOperation>();
    if (op == "cos")
        return std::make_unique<CosOperation>();
    if (op == "tan")
        return std::make_unique<TanOperation>();
    if (op == "log")
        return std::make_unique<LogOperation>();
    if (op == "ln")
        return std::make_unique<LnOperation>();
    if (op == "pow")
        return std::make_unique<PowerOperation>();
    if (op == "sqrt")
        return std::make_unique<SqrtOperation>();
    if (op == "fact")
        return std::make_unique<FactorialOperation>();

    throw std::runtime_error("Unknown operation");
}