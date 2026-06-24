#pragma once
#include <memory>
#include <string>
#include "Operation.h"

// factory class for creating operations
class OperationFactory
{
public:
    static std::unique_ptr<Operation> create(const std::string &op);
};