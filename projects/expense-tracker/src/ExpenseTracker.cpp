#include "../include/ExpenseTracker.h"
#include <fstream>
#include <sstream>
#include <iostream>

ExpenseTracker::ExpenseTracker(const std::string &path)
    : filePath(path)
{
    loadFromFile();
}

void ExpenseTracker::addIncome(const std::string &description, double amount)
{
    transactions.push_back({TransactionType::Income, description, amount});
}

void ExpenseTracker::addExpense(const std::string &description, double amount)
{
    transactions.push_back({TransactionType::Expense, description, amount});
}

double ExpenseTracker::getTotalIncome() const
{
    double total = 0;

    for (const auto &transaction : transactions)
    {
        if (transaction.type == TransactionType::Income)
        {
            total += transaction.amount;
        }
    }

    return total;
}

double ExpenseTracker::getTotalExpenses() const
{
    double total = 0;

    for (const auto &transaction : transactions)
    {
        if (transaction.type == TransactionType::Expense)
        {
            total += transaction.amount;
        }
    }

    return total;
}

double ExpenseTracker::getSavings() const
{
    return getTotalIncome() - getTotalExpenses();
}

const std::vector<Transaction> &ExpenseTracker::getTransactions() const
{
    return transactions;
}

void ExpenseTracker::saveToFile() const
{
    std::ofstream file(filePath);

    for (const auto &transaction : transactions)
    {
        std::string type =
            (transaction.type == TransactionType::Income)
                ? "income"
                : "expense";

        file << type << ","
             << transaction.description << ","
             << transaction.amount << "\n";
    }
}

void ExpenseTracker::loadFromFile()
{
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        return;
    }

    transactions.clear();

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string typeStr;
        std::string description;
        std::string amountStr;

        std::getline(ss, typeStr, ',');
        std::getline(ss, description, ',');
        std::getline(ss, amountStr, ',');

        TransactionType type =
            (typeStr == "income")
                ? TransactionType::Income
                : TransactionType::Expense;

        double amount = std::stod(amountStr);

        transactions.push_back({type, description, amount});
    }
}