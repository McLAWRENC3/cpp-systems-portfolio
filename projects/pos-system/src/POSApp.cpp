#include "../include/POSApp.h"
#include "../include/POSSystem.h"
#include <iostream>
#include <iomanip>

void POSApp::run()
{
    POSSystem pos;
    int choice;

    while (true)
    {
        std::cout << "\n===== POS System =====\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. View Inventory\n";
        std::cout << "3. Add To Cart\n";
        std::cout << "4. Checkout\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            std::string name;
            double price;
            int stock;

            std::cout << "Product Name: ";
            std::getline(std::cin, name);

            std::cout << "Price: ";
            std::cin >> price;

            std::cout << "Stock: ";
            std::cin >> stock;

            int id = pos.addProduct(name, price, stock);

            std::cout << "Product added with ID: " << id << "\n";
        }
        else if (choice == 2)
        {
            std::cout << "\nInventory:\n";

            for (const auto &product : pos.getProducts())
            {
                std::cout << product.productId
                          << " | "
                          << product.name
                          << " | "
                          << product.price
                          << " | Stock: "
                          << product.stock
                          << "\n";
            }
        }
        else if (choice == 3)
        {
            int productId;
            int quantity;

            std::cout << "Product ID: ";
            std::cin >> productId;

            std::cout << "Quantity: ";
            std::cin >> quantity;

            if (pos.addToCart(productId, quantity))
            {
                std::cout << "Added to cart.\n";
            }
            else
            {
                std::cout << "Failed to add to cart.\n";
            }
        }
        else if (choice == 4)
        {
            double total = pos.checkout();

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "\n===== RECEIPT =====\n";
            std::cout << "Total (incl. tax): " << total << "\n";

            pos.clearCart();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }
}