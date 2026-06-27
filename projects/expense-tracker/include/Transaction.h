#pragma once
#include <string>

// Represents transaction type
enum class TransactionType
{
    Income,
    Expense
};

// Represents one financial transaction
struct Transaction
{
    TransactionType type;
    std::string description;
    double amount;
};