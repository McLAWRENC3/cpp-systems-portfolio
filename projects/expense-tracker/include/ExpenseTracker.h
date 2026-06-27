#pragma once
#include "Transaction.h"
#include <vector>
#include <string>

// Handles all business logic and storage
class ExpenseTracker
{
private:
    std::vector<Transaction> transactions;
    std::string filePath;

public:
    ExpenseTracker(const std::string &path = "data/transactions.csv");

    void addIncome(const std::string &description, double amount);
    void addExpense(const std::string &description, double amount);

    double getTotalIncome() const;
    double getTotalExpenses() const;
    double getSavings() const;

    const std::vector<Transaction> &getTransactions() const;

    void saveToFile() const;
    void loadFromFile();
};