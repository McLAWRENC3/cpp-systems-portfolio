-- Remove old tables safely
DROP TABLE IF EXISTS salaries CASCADE;
DROP TABLE IF EXISTS employees CASCADE;
DROP TABLE IF EXISTS departments CASCADE;

-- Departments table
CREATE TABLE departments (
    department_id SERIAL PRIMARY KEY,
    department_name VARCHAR(100) UNIQUE NOT NULL
);

-- Employees table
CREATE TABLE employees (
    employee_id SERIAL PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    email VARCHAR(150) UNIQUE NOT NULL,
    department_id INT NOT NULL,
    CONSTRAINT fk_department
        FOREIGN KEY(department_id)
        REFERENCES departments(department_id)
);

-- Salaries table
CREATE TABLE salaries (
    salary_id SERIAL PRIMARY KEY,
    employee_id INT UNIQUE NOT NULL,
    base_salary NUMERIC(12,2) NOT NULL,
    bonus NUMERIC(12,2) DEFAULT 0,
    tax NUMERIC(12,2) DEFAULT 0,

    CONSTRAINT fk_employee
        FOREIGN KEY(employee_id)
        REFERENCES employees(employee_id)
);