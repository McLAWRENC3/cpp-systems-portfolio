#include "../include/ExpenseTrackerApp.h"
#include "../include/ExpenseTracker.h"
#include <iostream>
#include <iomanip>

void ExpenseTrackerApp::run()
{
    ExpenseTracker tracker;
    int choice;

    while (true)
    {
        std::cout << "\n===== Expense Tracker =====\n";
        std::cout << "1. Add Income\n";
        std::cout << "2. Add Expense\n";
        std::cout << "3. View Summary\n";
        std::cout << "4. View Transactions\n";
        std::cout << "5. Save and Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        if (choice == 1)
        {
            std::string description;
            double amount;

            std::cout << "Description: ";
            std::cin >> description;

            std::cout << "Amount: ";
            std::cin >> amount;

            tracker.addIncome(description, amount);
        }
        else if (choice == 2)
        {
            std::string description;
            double amount;

            std::cout << "Description: ";
            std::cin >> description;

            std::cout << "Amount: ";
            std::cin >> amount;

            tracker.addExpense(description, amount);
        }
        else if (choice == 3)
        {
            std::cout << std::fixed << std::setprecision(2);

            std::cout << "\nTotal Income: "
                      << tracker.getTotalIncome() << "\n";

            std::cout << "Total Expenses: "
                      << tracker.getTotalExpenses() << "\n";

            std::cout << "Savings: "
                      << tracker.getSavings() << "\n";
        }
        else if (choice == 4)
        {
            const auto &transactions = tracker.getTransactions();

            for (const auto &t : transactions)
            {
                std::string type =
                    (t.type == TransactionType::Income)
                        ? "Income"
                        : "Expense";

                std::cout << "[" << type << "] "
                          << t.description
                          << ": "
                          << t.amount
                          << "\n";
            }
        }
        else if (choice == 5)
        {
            tracker.saveToFile();
            std::cout << "Data saved.\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }
}