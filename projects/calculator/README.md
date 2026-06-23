# Calculator

## Overview

A command-line calculator built in modern C++.

Supports:

* Addition
* Subtraction
* Multiplication
* Division
* Decimal numbers

---

## Architecture

Layered architecture:

CLI
↓
Calculator Service
↓
Parser
↓
Operations

---

## Design Patterns Used

### Facade Pattern

`Calculator` provides a simple interface for expression evaluation.

### Strategy Pattern

Each arithmetic operation is encapsulated in its own class.

### Factory Pattern

`OperationFactory` creates operation objects based on operator symbols.

---

## Current Limitations

Version 1 evaluates expressions left-to-right.

Example:

2 + 3 * 4

Current result:
20

Correct mathematical result:
14

This will be fixed in Milestone 2 using:

* stacks
* precedence rules
* Shunting Yard algorithm
