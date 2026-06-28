#include "../include/PasswordManagerApp.h"
#include "../include/PasswordManager.h"
#include <iostream>

void PasswordManagerApp::run()
{
    PasswordManager manager;
    std::string master;

    if (!manager.masterPasswordExists())
    {
        std::cout << "Create master password: ";
        std::getline(std::cin, master);
        manager.setupMasterPassword(master);
        std::cout << "Master password created.\n";
    }

    std::cout << "Enter master password: ";
    std::getline(std::cin, master);

    if (!manager.login(master))
    {
        std::cout << "Access denied.\n";
        return;
    }

    int choice;

    while (true)
    {
        std::cout << "\n===== Password Manager =====\n";
        std::cout << "1. Add Credential\n";
        std::cout << "2. View Credentials\n";
        std::cout << "3. Reveal Password\n";
        std::cout << "4. Delete Credential\n";
        std::cout << "5. Save and Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            std::string service, username, password;

            std::cout << "Service: ";
            std::getline(std::cin, service);

            std::cout << "Username: ";
            std::getline(std::cin, username);

            std::cout << "Password: ";
            std::getline(std::cin, password);

            manager.addCredential(service, username, password);
        }
        else if (choice == 2)
        {
            for (const auto &c : manager.getCredentials())
            {
                std::cout << c.id << " | "
                          << c.service << " | "
                          << c.username << " | "
                          << "********\n";
            }
        }
        else if (choice == 3)
        {
            int id;
            std::cout << "Credential ID: ";
            std::cin >> id;

            std::string password = manager.revealPassword(id);

            if (password.empty())
            {
                std::cout << "Credential not found.\n";
            }
            else
            {
                std::cout << "Password: " << password << "\n";
            }
        }
        else if (choice == 4)
        {
            int id;
            std::cout << "Credential ID to delete: ";
            std::cin >> id;

            if (manager.deleteCredential(id))
            {
                std::cout << "Deleted.\n";
            }
            else
            {
                std::cout << "Credential not found.\n";
            }
        }
        else if (choice == 5)
        {
            manager.saveToFile();
            std::cout << "Saved.\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }
}