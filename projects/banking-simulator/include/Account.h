#pragma once
#include <string>

// Represents a bank account
struct Account
{
    int accountId;
    std::string ownerName;
    long long balanceCents; // Store money in cents to avoid floating-point errors
};