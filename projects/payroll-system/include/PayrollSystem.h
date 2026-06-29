#pragma once
#include "Employee.h"
#include <vector>
#include <string>

// handles payroll bussiness logic
class PayrollSystem
{
private:
    std::vector<Employee> employees;
    int nextEmployeeId;
    Employee *findEmployee(int employeeId);

public:
    PayrollSystem();
    int addEmployee(
        const std::string &name,
        double hourlyRate,
        double hoursWorked,
        double overtimeHour);

    double calculateBaseSalary(int employeeId);
    double calculateOvertimePay(int employeeId);
    double calculateGrossSalary(int employeeId);
    double calculateTax(int employeeId);
    double calculateNetSalary(int employeeId);

    const std::vector<Employee> &getEmployees() const;
};