INSERT INTO products (product_name, price, stock)
VALUES
('Laptop', 25000.00, 15),
('Mechanical Keyboard', 1800.00, 40),
('Gaming Mouse', 950.00, 30);

INSERT INTO carts (user_id)
VALUES
(1),
(2);

INSERT INTO cart_items (cart_id, product_id, quantity)
VALUES
(1, 1, 1),
(1, 2, 2),
(2, 3, 1); 