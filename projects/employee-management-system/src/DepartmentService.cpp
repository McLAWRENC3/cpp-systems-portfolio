#include "../include/DepartmentService.h"
#include <iostream>

DepartmentService::DepartmentService(DatabaseManager& databaseManager)
    : db(databaseManager) {}

void DepartmentService::getAllDepartments() {
    try {
        pqxx::work txn(db.getConnection());

        pqxx::result result =
            txn.exec("SELECT * FROM departments");

        for (const auto& row : result) {
            std::cout
                << row["department_id"].as<int>()
                << " | "
                << row["department_name"].c_str()
                << "\n";
        }

        txn.commit();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}