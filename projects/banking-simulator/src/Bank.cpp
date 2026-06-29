#include "../include/Bank.h"

// Constructor initializes account IDs
Bank::Bank() : nextAccountId(1001) {}

Account *Bank::findAccount(int accountId)
{
    for (auto &account : accounts)
    {
        if (account.accountId == accountId)
        {
            return &account;
        }
    }
    return nullptr;
}

int Bank::createAccount(const std::string &ownerName)
{
    Account account;
    account.accountId = nextAccountId++;
    account.ownerName = ownerName;
    account.balanceCents = 0;

    accounts.push_back(account);
    return account.accountId;
}

bool Bank::deposit(int accountId, long long amountCents)
{
    Account *account = findAccount(accountId);

    if (!account || amountCents <= 0)
    {
        return false;
    }

    account->balanceCents += amountCents;

    transactions.push_back({accountId,
                            "Deposit",
                            amountCents,
                            "Money deposited"});

    return true;
}

bool Bank::withdraw(int accountId, long long amountCents)
{
    Account *account = findAccount(accountId);

    if (!account || amountCents <= 0)
    {
        return false;
    }

    if (account->balanceCents < amountCents)
    {
        return false;
    }

    account->balanceCents -= amountCents;

    transactions.push_back({accountId,
                            "Withdraw",
                            amountCents,
                            "Money withdrawn"});

    return true;
}

bool Bank::transfer(int fromId, int toId, long long amountCents)
{
    Account *from = findAccount(fromId);
    Account *to = findAccount(toId);

    if (!from || !to || amountCents <= 0)
    {
        return false;
    }

    if (from->balanceCents < amountCents)
    {
        return false;
    }

    // Atomic transaction: validate first, then mutate both
    from->balanceCents -= amountCents;
    to->balanceCents += amountCents;

    transactions.push_back({fromId,
                            "Transfer Out",
                            amountCents,
                            "Sent to account " + std::to_string(toId)});

    transactions.push_back({toId,
                            "Transfer In",
                            amountCents,
                            "Received from account " + std::to_string(fromId)});

    return true;
}

const std::vector<Account> &Bank::getAccounts() const
{
    return accounts;
}

std::vector<Transaction> Bank::getStatements(int accountId) const
{
    std::vector<Transaction> result;

    for (const auto &tx : transactions)
    {
        if (tx.accountId == accountId)
        {
            result.push_back(tx);
        }
    }

    return result;
}