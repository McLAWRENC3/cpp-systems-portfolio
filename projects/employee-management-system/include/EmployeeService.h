#pragma once
#include "DatabaseManager.h"
#include <string>

// Handles employee-related operations
class EmployeeService {
private:
    DatabaseManager& db;

public:
    EmployeeService(DatabaseManager& databaseManager);

    void addEmployee(
        const std::string& firstName,
        const std::string& lastName,
        const std::string& email,
        int departmentId
    );

    void getEmployeesWithDepartments();
};