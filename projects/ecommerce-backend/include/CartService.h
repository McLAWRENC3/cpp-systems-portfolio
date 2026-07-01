#pragma once
#include "DatabaseManager.h"

class CartService
{
private:
    DatabaseManager &db;

public:
    CartService(DatabaseManager &dbManager);

    void viewCart(int userId);
};