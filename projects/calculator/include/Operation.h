#pragma once
#include <memory>
#include <stdexcept>

class Operation {
public:
    virtual ~Operation() = default;
    virtual double execute(double a, double b) const = 0;
};

class AddOperation : public Operation {
public:
    double execute(double a, double b) const override;
};

class SubOperation : public Operation {
public:
    double execute(double a, double b) const override;
};

class MulOperation : public Operation {
public:
    double execute(double a, double b) const override;
};

class DivOperation : public Operation {
public:
    double execute(double a, double b) const override;
};

class OperationFactory {
public:
    static std::unique_ptr<Operation> create(char op);
};