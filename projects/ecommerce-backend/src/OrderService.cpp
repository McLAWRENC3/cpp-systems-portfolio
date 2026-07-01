#include "../include/OrderService.h"
#include <iostream>

OrderService::OrderService(DatabaseManager &dbManager)
    : db(dbManager) {}

void OrderService::checkout(int userId)
{
    try
    {
        pqxx::work txn(db.getConnection());

        auto cartItems = txn.exec(
            "SELECT p.product_id, p.price, p.stock, ci.quantity "
            "FROM carts c "
            "JOIN cart_items ci ON c.cart_id=ci.cart_id "
            "JOIN products p ON p.product_id=ci.product_id "
            "WHERE c.user_id=" +
            txn.quote(userId));

        double total = 0;

        for (auto row : cartItems)
        {
            int stock = row["stock"].as<int>();
            int qty = row["quantity"].as<int>();

            if (qty > stock)
            {
                throw std::runtime_error("Insufficient stock");
            }

            total += row["price"].as<double>() * qty;
        }

        auto orderResult = txn.exec(
            "INSERT INTO orders(user_id,total_amount,status) VALUES (" +
            txn.quote(userId) + "," +
            txn.quote(total) + ",'paid') RETURNING order_id");

        int orderId = orderResult[0]["order_id"].as<int>();

        for (auto row : cartItems)
        {
            int productId = row["product_id"].as<int>();
            int qty = row["quantity"].as<int>();
            double price = row["price"].as<double>();

            txn.exec(
                "INSERT INTO order_items(order_id,product_id,quantity,price_at_purchase) VALUES (" +
                txn.quote(orderId) + "," +
                txn.quote(productId) + "," +
                txn.quote(qty) + "," +
                txn.quote(price) + ")");

            txn.exec(
                "UPDATE products SET stock = stock - " +
                txn.quote(qty) +
                " WHERE product_id=" + txn.quote(productId));
        }

        txn.exec(
            "DELETE FROM cart_items WHERE cart_id IN "
            "(SELECT cart_id FROM carts WHERE user_id=" +
            txn.quote(userId) + ")");

        txn.commit();

        std::cout << "Checkout successful.\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Transaction failed: " << e.what() << "\n";
    }
}