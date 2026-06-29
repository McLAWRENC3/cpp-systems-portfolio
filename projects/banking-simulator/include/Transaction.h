#pragma once
#include <string>

// Represents a transaction record
struct Transaction
{
    int accountId;
    std::string type;
    long long amountCents;
    std::string description;
};