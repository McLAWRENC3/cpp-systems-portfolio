INSERT INTO departments (department_name)
VALUES
('Engineering'),
('Finance'),
('HR');

INSERT INTO employees (
    first_name,
    last_name,
    email,
    department_id
)
VALUES
('Lawrence', 'Mwila', 'lawrence@email.com', 1),
('Alice', 'Brown', 'alice@email.com', 2),
('John', 'Smith', 'john@email.com', 1);

INSERT INTO salaries (
    employee_id,
    base_salary,
    bonus,
    tax
)
VALUES
(1, 120000, 5000, 18000),
(2, 95000, 3000, 14000),
(3, 130000, 7000, 22000);