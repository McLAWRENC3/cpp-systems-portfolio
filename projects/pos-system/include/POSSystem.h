#pragma once
#include "Product.h"
#include "CartItem.h"
#include <vector>
#include <string>

// Core POS business logic
class POSSystem
{
private:
    std::vector<Product> products;
    std::vector<CartItem> cart;
    int nextProductId;

    Product *findProduct(int productId);

public:
    POSSystem();

    int addProduct(const std::string &name, double price, int stock);
    bool addToCart(int productId, int quantity);

    const std::vector<Product> &getProducts() const;
    const std::vector<CartItem> &getCart() const;

    double checkout();
    void clearCart();
};