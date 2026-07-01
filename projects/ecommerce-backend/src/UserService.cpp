#include "../include/UserService.h"
#include <iostream>

UserService::UserService(DatabaseManager &dbManager)
    : db(dbManager) {}

void UserService::createUser(
    const std::string &name,
    const std::string &email,
    const std::string &passwordHash)
{
    try
    {
        pqxx::work txn(db.getConnection());

        txn.exec(
            "INSERT INTO users(full_name,email,password_hash) VALUES (" +
            txn.quote(name) + "," +
            txn.quote(email) + "," +
            txn.quote(passwordHash) + ")");

        txn.commit();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
}

void UserService::getAllUsers()
{
    pqxx::work txn(db.getConnection());
    auto result = txn.exec("SELECT * FROM users");

    for (auto row : result)
    {
        std::cout
            << row["user_id"].as<int>()
            << " | "
            << row["full_name"].c_str()
            << "\n";
    }
}