#include "../include/PayrollApp.h"
#include "../include/PayrollSystem.h"
#include <iostream>
#include <iomanip>

void PayrollApp::run()
{
    PayrollSystem payroll;
    int choice;

    while (true)
    {
        std::cout << "\n===== Payroll System =====\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. View Employees\n";
        std::cout << "3. Generate Payslip\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            std::string name;
            double rate;
            double hours;
            double overtime;

            std::cout << "Employee Name: ";
            std::getline(std::cin, name);

            std::cout << "Hourly Rate: ";
            std::cin >> rate;

            std::cout << "Hours Worked: ";
            std::cin >> hours;

            std::cout << "Overtime Hours: ";
            std::cin >> overtime;

            int id = payroll.addEmployee(name, rate, hours, overtime);

            std::cout << "Employee added. ID: " << id << "\n";
        }
        else if (choice == 2)
        {
            for (const auto &employee : payroll.getEmployees())
            {
                std::cout << employee.employeeId
                          << " | "
                          << employee.name
                          << "\n";
            }
        }
        else if (choice == 3)
        {
            int id;
            std::cout << "Employee ID: ";
            std::cin >> id;

            double base = payroll.calculateBaseSalary(id);
            double overtime = payroll.calculateOvertimePay(id);
            double gross = payroll.calculateGrossSalary(id);
            double tax = payroll.calculateTax(id);
            double net = payroll.calculateNetSalary(id);

            if (gross == 0)
            {
                std::cout << "Employee not found.\n";
                continue;
            }

            std::cout << std::fixed << std::setprecision(2);

            std::cout << "\n===== PAYSLIP =====\n";
            std::cout << "Base Salary : " << base << "\n";
            std::cout << "Overtime Pay: " << overtime << "\n";
            std::cout << "Gross Salary: " << gross << "\n";
            std::cout << "Tax (20%)   : " << tax << "\n";
            std::cout << "Net Salary  : " << net << "\n";
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }
}