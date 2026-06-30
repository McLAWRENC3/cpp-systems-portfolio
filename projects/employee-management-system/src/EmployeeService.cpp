#include "../include/EmployeeService.h"
#include <iostream>

EmployeeService::EmployeeService(DatabaseManager& databaseManager)
    : db(databaseManager) {}

void EmployeeService::addEmployee(
    const std::string& firstName,
    const std::string& lastName,
    const std::string& email,
    int departmentId
) {
    try {
        pqxx::work txn(db.getConnection());

        txn.exec_params(
            "INSERT INTO employees "
            "(first_name, last_name, email, department_id) "
            "VALUES ($1, $2, $3, $4)",
            firstName,
            lastName,
            email,
            departmentId
        );

        txn.commit();
        std::cout << "Employee added successfully.\n";
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}

void EmployeeService::getEmployeesWithDepartments() {
    try {
        pqxx::work txn(db.getConnection());

        pqxx::result result = txn.exec(
            "SELECT e.employee_id, e.first_name, e.last_name, "
            "e.email, d.department_name "
            "FROM employees e "
            "JOIN departments d "
            "ON e.department_id = d.department_id"
        );

        for (const auto& row : result) {
            std::cout
                << row["employee_id"].as<int>() << " | "
                << row["first_name"].c_str() << " | "
                << row["last_name"].c_str() << " | "
                << row["email"].c_str() << " | "
                << row["department_name"].c_str()
                << "\n";
        }

        txn.commit();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}