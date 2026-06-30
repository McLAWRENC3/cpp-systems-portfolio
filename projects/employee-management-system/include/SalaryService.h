#pragma once
#include "DatabaseManager.h"

// Handles salary-related operations
class SalaryService {
private:
    DatabaseManager& db;

public:
    SalaryService(DatabaseManager& databaseManager);

    void getPayrollReport();
};