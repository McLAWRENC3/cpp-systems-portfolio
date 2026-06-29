#pragma once
#include <string>
// represents an employee in the  payroll system

struct Employee
{
    int employeeId;
    std::string name;
    double hourlyRate;
    double hoursWorked;
    double overtimeHours;
};