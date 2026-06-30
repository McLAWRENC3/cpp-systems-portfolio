#include "../include/SalaryService.h"
#include <iostream>

SalaryService::SalaryService(DatabaseManager& databaseManager)
    : db(databaseManager) {}

void SalaryService::getPayrollReport() {
    try {
        pqxx::work txn(db.getConnection());

        pqxx::result result = txn.exec(
            "SELECT e.first_name, e.last_name, "
            "s.base_salary, s.bonus, s.tax "
            "FROM employees e "
            "JOIN salaries s "
            "ON e.employee_id = s.employee_id"
        );

        for (const auto& row : result) {
            std::cout
                << row["first_name"].c_str() << " "
                << row["last_name"].c_str()
                << " | Salary: "
                << row["base_salary"].as<double>()
                << " | Bonus: "
                << row["bonus"].as<double>()
                << " | Tax: "
                << row["tax"].as<double>()
                << "\n";
        }

        txn.commit();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}