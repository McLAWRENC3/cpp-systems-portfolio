#pragma once
#include <string>
// represents a product in the inventory
struct Product
{
    int productId;
    std::string name;
    double price;
    int stock;
};