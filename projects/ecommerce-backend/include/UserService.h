#pragma once
#include "DatabaseManager.h"
#include <string>

class UserService
{
private:
    DatabaseManager &db;

public:
    UserService(DatabaseManager &dbManager);

    void createUser(
        const std::string &name,
        const std::string &email,
        const std::string &passwordHash);

    void getAllUsers();
};