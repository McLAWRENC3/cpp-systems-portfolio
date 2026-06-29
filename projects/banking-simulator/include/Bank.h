#pragma once
#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <string>

// Core banking logic
class Bank
{
private:
    std::vector<Account> accounts;
    std::vector<Transaction> transactions;
    int nextAccountId;

    Account *findAccount(int accountId);

public:
    Bank();

    int createAccount(const std::string &ownerName);

    bool deposit(int accountId, long long amountCents);
    bool withdraw(int accountId, long long amountCents);
    bool transfer(int fromId, int toId, long long amountCents);

    const std::vector<Account> &getAccounts() const;
    std::vector<Transaction> getStatements(int accountId) const;
};