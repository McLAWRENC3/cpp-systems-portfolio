#include "../include/DatabaseManager.h"
#include "../include/UserService.h"
#include "../include/ProductService.h"
#include "../include/CartService.h"
#include "../include/OrderService.h"

int main()
{
    std::string conn =
        "dbname=ecommerce_backend user=postgres password=ADMIN123 host=localhost port=5432";

    DatabaseManager db(conn);

    if (!db.isConnected())
    {
        return 1;
    }

    UserService userService(db);
    ProductService productService(db);
    CartService cartService(db);
    OrderService orderService(db);

    userService.getAllUsers();
    productService.getAllProducts();
    cartService.viewCart(1);
    orderService.checkout(1);

    return 0;
}