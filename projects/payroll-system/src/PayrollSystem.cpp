#include "../include/PayrollSystem.h"

PayrollSystem::PayrollSystem() : nextEmployeeId(1001) {}

Employee *PayrollSystem::findEmployee(int employeeId)
{
    for (auto &employee : employees)
    {
        if (employee.employeeId == employeeId)
        {
            return &employee;
        }
    }
    return nullptr;
}

int PayrollSystem::addEmployee(
    const std::string &name,
    double hourlyRate,
    double hoursWorked,
    double overtimeHours)
{
    Employee employee;
    employee.employeeId = nextEmployeeId++;
    employee.name = name;
    employee.hourlyRate = hourlyRate;
    employee.hoursWorked = hoursWorked;
    employee.overtimeHours = overtimeHours;

    employees.push_back(employee);
    return employee.employeeId;
}

double PayrollSystem::calculateBaseSalary(int employeeId)
{
    Employee *employee = findEmployee(employeeId);
    if (!employee)
        return 0;

    return employee->hourlyRate * employee->hoursWorked;
}

double PayrollSystem::calculateOvertimePay(int employeeId)
{
    Employee *employee = findEmployee(employeeId);
    if (!employee)
        return 0;

    return employee->overtimeHours * employee->hourlyRate * 1.5;
}

double PayrollSystem::calculateGrossSalary(int employeeId)
{
    return calculateBaseSalary(employeeId) + calculateOvertimePay(employeeId);
}

double PayrollSystem::calculateTax(int employeeId)
{
    return calculateGrossSalary(employeeId) * 0.20;
}

double PayrollSystem::calculateNetSalary(int employeeId)
{
    return calculateGrossSalary(employeeId) - calculateTax(employeeId);
}

const std::vector<Employee> &PayrollSystem::getEmployees() const
{
    return employees;
}