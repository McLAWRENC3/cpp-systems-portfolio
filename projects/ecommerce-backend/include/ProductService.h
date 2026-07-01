#pragma once
#include "DatabaseManager.h"
#include <string>

class ProductService
{
private:
    DatabaseManager &db;

public:
    ProductService(DatabaseManager &dbManager);

    void addProduct(
        const std::string &name,
        double price,
        int stock);

    void getAllProducts();
};