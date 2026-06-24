#pragma once
// the base abstract class for all operations

class Operation
{
public:
    virtual ~Operation() = default;
    virtual double execute(double a, double b = 0) const = 0;
};