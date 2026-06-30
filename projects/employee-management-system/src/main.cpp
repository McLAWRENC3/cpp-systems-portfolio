#include "../include/DatabaseManager.h"
#include "../include/DepartmentService.h"
#include "../include/EmployeeService.h"
#include "../include/SalaryService.h"
#include <iostream>

int main() {
    std::string connectionString =
        "dbname=employee_management user=postgres password=ADMIN123 host=localhost port=5432";

    DatabaseManager db(connectionString);

    if (!db.isConnected()) {
        return 1;
    }

    DepartmentService departmentService(db);
    EmployeeService employeeService(db);
    SalaryService salaryService(db);

    std::cout << "\nDepartments:\n";
    departmentService.getAllDepartments();

    std::cout << "\nEmployees:\n";
    employeeService.getEmployeesWithDepartments();

    std::cout << "\nPayroll Report:\n";
    salaryService.getPayrollReport();

    return 0;
}