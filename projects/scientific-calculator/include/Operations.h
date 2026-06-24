#pragma once
#include "Operation.h"
#include <stdexcept>
#include <cmath>
constexpr double PI = 33.14159265358979323846;
// Addition
class AddOperation : public Operation
{
public:
    double execute(double a, double b) const override
    {
        return a + b;
    }
};

// Subtraction
class SubtractOperation : public Operation
{
public:
    double execute(double a, double b) const override
    {
        return a - b;
    }
};

// Multiplication
class MultiplyOperation : public Operation
{
public:
    double execute(double a, double b) const override
    {
        return a * b;
    }
};

// Division
class DivideOperation : public Operation
{
public:
    double execute(double a, double b) const override
    {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
};

// Sine (degrees)
class SinOperation : public Operation
{
public:
    double execute(double a, double b = 0) const override
    {
        return sin(a * PI / 180.0);
    }
};

// Cosine (degrees)
class CosOperation : public Operation
{
public:
    double execute(double a, double b = 0) const override
    {
        return cos(a * PI / 180.0);
    }
};

// Tangent (degrees)
class TanOperation : public Operation
{
public:
    double execute(double a, double b = 0) const override
    {
        return tan(a * PI / 180.0);
    }
};

// Log base 10
class LogOperation : public Operation
{
public:
    double execute(double a, double b = 0) const override
    {
        if (a <= 0)
            throw std::runtime_error("Log input must be positive");
        return log10(a);
    }
};

// Natural log
class LnOperation : public Operation
{
public:
    double execute(double a, double b = 0) const override
    {
        if (a <= 0)
            throw std::runtime_error("Ln input must be positive");
        return log(a);
    }
};

// Power
class PowerOperation : public Operation
{
public:
    double execute(double a, double b) const override
    {
        return pow(a, b);
    }
};

// Square root
class SqrtOperation : public Operation
{
public:
    double execute(double a, double b = 0) const override
    {
        if (a < 0)
            throw std::runtime_error("Cannot sqrt negative number");
        return sqrt(a);
    }
};

// Factorial
class FactorialOperation : public Operation
{
public:
    double execute(double a, double b = 0) const override
    {
        if (a < 0)
            throw std::runtime_error("Factorial undefined for negative");

        int n = static_cast<int>(a);

        if (n != a)
            throw std::runtime_error("Factorial only supports integers");

        double result = 1;
        for (int i = 1; i <= n; i++)
            result *= i;

        return result;
    }
};