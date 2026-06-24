# Scientific Calculator

A console-based scientific calculator built in modern C++.

This project extends the basic calculator by adding advanced mathematical operations such as trigonometry, logarithms, powers, factorials, and square roots.

---

# 1. Requirements Engineering

## Problem Statement

The goal is to build a scientific calculator that performs both basic arithmetic and advanced mathematical operations through a command-line interface.

The application should be:

- Easy to use
- Modular
- Maintainable
- Extendable
- Reliable

---

## Functional Requirements

The calculator must support the following operations:

### Arithmetic Operations
- Addition
- Subtraction
- Multiplication
- Division

### Scientific Operations
- Sine
- Cosine
- Tangent
- Logarithm (base 10)
- Natural Logarithm
- Power
- Square Root
- Factorial

Example inputs:

```text
add 4 5
sin 90
pow 2 8
fact 5
```

Expected outputs:

```text
9
1
256
120
```

---

## Non-Functional Requirements

The system should be:

- Fast
- Robust against invalid input
- Easy to extend with new operations
- Architecturally clean
- Cross-platform

Constraints:

- Console-based only
- Built using C++17
- No external libraries required

---

# 2. System Design

The application uses layered architecture.

## High-Level Architecture

```text
User Input (CLI)
      ↓
 Calculator Engine
      ↓
 Operation Factory
      ↓
 Concrete Operations
```

---

## Components

### CLI Layer
Responsible for:

- Reading user input
- Displaying results
- Error messaging

---

### Calculator Engine
Responsible for:

- Managing execution flow
- Calling correct operations
- Handling exceptions

---

### Operation Factory
Responsible for:

- Creating operation objects dynamically
- Decoupling object creation from business logic

---

### Operation Classes
Each mathematical operation is implemented as an independent class.

Examples:

- AddOperation
- SinOperation
- LogOperation
- FactorialOperation

This improves modularity.

---

# 3. UML Design

## Class Diagram

```text
                +------------------+
                |    Operation     |
                +------------------+
                | + execute()      |
                +------------------+
                         ▲
                         |
      -----------------------------------------
      |        |        |       |      |      |
     Add      Sub      Sin     Log    Pow   Fact
```

---

## Relationship Summary

### Inheritance
All concrete operations inherit from:

```cpp
Operation
```

This enables polymorphism.

---

### Composition
Calculator uses:

```cpp
OperationFactory
```

Factory creates operation objects used by calculator.

---

# 4. Implementation

Implementation follows clean modular C++ design.

## Files

```text
scientific-calculator/
│
├── include/
│   ├── Calculator.h
│   ├── Operation.h
│   ├── Operations.h
│   └── OperationFactory.h
│
├── src/
│   ├── Calculator.cpp
│   ├── OperationFactory.cpp
│   └── main.cpp
│
└── CMakeLists.txt
```

---

## Core C++ Features Used

### Classes
Used to encapsulate behavior.

Example:

```cpp
class AddOperation
```

---

### Abstract Classes
Used for operation interface.

```cpp
virtual double execute(...) = 0;
```

---

### Virtual Functions
Used for runtime polymorphism.

Allows:

```cpp
operation->execute(...)
```

without knowing concrete type.

---

### Smart Pointers

Used:

```cpp
std::unique_ptr
```

Benefits:

- Automatic memory management
- Prevents memory leaks
- RAII-compliant

---

### Exception Handling

Used for invalid operations:

Examples:

- division by zero
- sqrt of negative number
- invalid log input

Example:

```cpp
throw std::runtime_error(...)
```

---

# 5. Design Patterns & Engineering Decisions

## Strategy Pattern

Each mathematical operation acts as a strategy.

Examples:

- Add strategy
- Sin strategy
- Log strategy

Why?

Because each operation has interchangeable behavior.

---

## Factory Pattern

Factory creates operations dynamically.

Example:

```cpp
OperationFactory::create("sin")
```

Benefits:

- Cleaner calculator logic
- Easier extensibility
- Reduced coupling

---

## Engineering Decisions

### Decision 1: OOP vs Function Map

Alternative:

```cpp
unordered_map<string, function<double()>>
```

Chosen:
- OOP with polymorphism

Reason:
- Better architecture practice
- Easier to scale

---

### Decision 2: Iterative Factorial

Alternative:

Recursive factorial

Chosen:
- Iterative factorial

Reason:
- Avoid recursion overhead
- No stack growth

---

### Decision 3: constexpr PI

Chosen:

```cpp
constexpr double PI = 3.14159265358979323846;
```

Reason:
- Portable
- Compile-time constant
- Avoids compiler-specific `M_PI`

---

# 6. Testing & Validation

The following tests were performed.

---

## Arithmetic Tests

| Input | Expected |
|---|---|
| add 2 3 | 5 |
| sub 10 4 | 6 |
| mul 6 7 | 42 |
| div 20 5 | 4 |

---

## Scientific Tests

| Input | Expected |
|---|---|
| sin 90 | 1 |
| cos 0 | 1 |
| tan 45 | 1 |
| log 100 | 2 |
| ln 1 | 0 |
| pow 2 8 | 256 |
| sqrt 16 | 4 |
| fact 5 | 120 |

---

## Edge Cases

Tested:

### Division by Zero

Input:

```text
div 10 0
```

Expected:

```text
Error
```

---

### Negative Square Root

Input:

```text
sqrt -9
```

Expected:

```text
Error
```

---

### Invalid Factorial

Input:

```text
fact 3.5
```

Expected:

```text
Error
```

---

# 7. Performance Analysis

Although this is a small application, performance considerations were still evaluated.

---

## Time Complexity

Most operations:

```text
O(1)
```

Examples:

- add
- sin
- cos
- sqrt
- log

---

### Factorial

Complexity:

```text
O(n)
```

because loop runs from:

```text
1 → n
```

---

## Memory Usage

Operations are lightweight.

Memory characteristics:

- Minimal heap allocation
- Small object sizes
- Automatic cleanup via smart pointers

---

## Optimization Considerations

Potential future optimizations:

- Replace virtual dispatch with templates
- Reduce heap allocations
- Add compile-time function dispatch
- Add expression parser

---

# Future Improvements

Planned upgrades:

- Expression parsing  
  Example:

```text
sin(90) + log(100)
```

- Operator precedence
- Memory/history
- Graphing
- GUI version using :contentReference[oaicite:0]{index=0} or :contentReference[oaicite:1]{index=1}
- Unit testing with :contentReference[oaicite:2]{index=2}

---

# Build Instructions

Using manual compilation:

```bash
g++ src/*.cpp -Iinclude -std=c++17 -o scientific_calculator
```

Run:

```bash
./scientific_calculator
```

Or using :contentReference[oaicite:3]{index=3}:

```bash
cmake -B build
cmake --build build
```
