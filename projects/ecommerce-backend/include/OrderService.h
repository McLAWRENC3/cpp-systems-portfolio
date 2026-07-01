#pragma once
#include "DatabaseManager.h"

class OrderService
{
private:
    DatabaseManager &db;

public:
    OrderService(DatabaseManager &dbManager);

    void checkout(int userId);
};