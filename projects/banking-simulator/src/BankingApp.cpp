#include "../include/BankingApp.h"
#include "../include/Bank.h"
#include <iostream>
#include <iomanip>

void BankingApp::run()
{
    Bank bank;
    int choice;

    while (true)
    {
        std::cout << "\n===== Banking Simulator =====\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Transfer\n";
        std::cout << "5. View Accounts\n";
        std::cout << "6. View Statement\n";
        std::cout << "7. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            std::string name;
            std::cout << "Owner name: ";
            std::getline(std::cin, name);

            int id = bank.createAccount(name);
            std::cout << "Account created. ID: " << id << "\n";
        }
        else if (choice == 2)
        {
            int id;
            long long amount;

            std::cout << "Account ID: ";
            std::cin >> id;

            std::cout << "Amount (cents): ";
            std::cin >> amount;

            if (bank.deposit(id, amount))
                std::cout << "Deposit successful.\n";
            else
                std::cout << "Deposit failed.\n";
        }
        else if (choice == 3)
        {
            int id;
            long long amount;

            std::cout << "Account ID: ";
            std::cin >> id;

            std::cout << "Amount (cents): ";
            std::cin >> amount;

            if (bank.withdraw(id, amount))
                std::cout << "Withdrawal successful.\n";
            else
                std::cout << "Withdrawal failed.\n";
        }
        else if (choice == 4)
        {
            int fromId, toId;
            long long amount;

            std::cout << "From Account ID: ";
            std::cin >> fromId;

            std::cout << "To Account ID: ";
            std::cin >> toId;

            std::cout << "Amount (cents): ";
            std::cin >> amount;

            if (bank.transfer(fromId, toId, amount))
                std::cout << "Transfer successful.\n";
            else
                std::cout << "Transfer failed.\n";
        }
        else if (choice == 5)
        {
            for (const auto &account : bank.getAccounts())
            {
                std::cout << account.accountId
                          << " | " << account.ownerName
                          << " | $" << std::fixed << std::setprecision(2)
                          << account.balanceCents / 100.0
                          << "\n";
            }
        }
        else if (choice == 6)
        {
            int id;
            std::cout << "Account ID: ";
            std::cin >> id;

            auto statements = bank.getStatements(id);

            for (const auto &tx : statements)
            {
                std::cout << tx.type
                          << " | $"
                          << tx.amountCents / 100.0
                          << " | "
                          << tx.description
                          << "\n";
            }
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }
}