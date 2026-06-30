#pragma once
#include "DatabaseManager.h"

// Handles department-related database operations
class DepartmentService {
private:
    DatabaseManager& db;

public:
    DepartmentService(DatabaseManager& databaseManager);

    void getAllDepartments();
};