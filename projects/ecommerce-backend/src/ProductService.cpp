
#include "../include/ProductService.h"
#include <iostream>

ProductService::ProductService(DatabaseManager &dbManager)
    : db(dbManager) {}

void ProductService::addProduct(
    const std::string &name,
    double price,
    int stock)
{
    pqxx::work txn(db.getConnection());

    txn.exec(
        "INSERT INTO products(product_name,price,stock) VALUES (" +
        txn.quote(name) + "," +
        txn.quote(price) + "," +
        txn.quote(stock) + ")");

    txn.commit();
}

void ProductService::getAllProducts()
{
    pqxx::work txn(db.getConnection());
    auto result = txn.exec("SELECT * FROM products");

    for (auto row : result)
    {
        std::cout
            << row["product_name"].c_str()
            << " | "
            << row["price"].as<double>()
            << "\n";
    }
}