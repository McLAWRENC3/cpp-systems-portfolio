#include "../include/CartService.h"
#include <iostream>

CartService::CartService(DatabaseManager &dbManager)
    : db(dbManager) {}

void CartService::viewCart(int userId)
{
    pqxx::work txn(db.getConnection());

    auto result = txn.exec(
        "SELECT p.product_name, ci.quantity, p.price "
        "FROM carts c "
        "JOIN cart_items ci ON c.cart_id=ci.cart_id "
        "JOIN products p ON p.product_id=ci.product_id "
        "WHERE c.user_id=" +
        txn.quote(userId));

    for (auto row : result)
    {
        std::cout
            << row["product_name"].c_str()
            << " | Qty: "
            << row["quantity"].as<int>()
            << " | Price: "
            << row["price"].as<double>()
            << "\n";
    }
}