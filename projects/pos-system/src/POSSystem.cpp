#include "../include/POSSystem.h"

POSSystem::POSSystem() : nextProductId(101) {}

Product *POSSystem::findProduct(int productId)
{
    for (auto &product : products)
    {
        if (product.productId == productId)
        {
            return &product;
        }
    }
    return nullptr;
}

int POSSystem::addProduct(const std::string &name, double price, int stock)
{
    Product product;
    product.productId = nextProductId++;
    product.name = name;
    product.price = price;
    product.stock = stock;

    products.push_back(product);
    return product.productId;
}

bool POSSystem::addToCart(int productId, int quantity)
{
    Product *product = findProduct(productId);

    if (!product || quantity <= 0)
    {
        return false;
    }

    if (product->stock < quantity)
    {
        return false;
    }

    product->stock -= quantity;

    cart.push_back({productId, quantity});
    return true;
}

const std::vector<Product> &POSSystem::getProducts() const
{
    return products;
}

const std::vector<CartItem> &POSSystem::getCart() const
{
    return cart;
}

double POSSystem::checkout()
{
    double subtotal = 0.0;

    for (const auto &item : cart)
    {
        Product *product = findProduct(item.productId);

        if (product)
        {
            subtotal += product->price * item.quantity;
        }
    }

    double tax = subtotal * 0.16;
    return subtotal + tax;
}

void POSSystem::clearCart()
{
    cart.clear();
}