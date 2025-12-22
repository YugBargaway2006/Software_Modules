# Strategy Design Pattern

**Key principle:**

> Favor composition over conditional logic for algorithm selection.

---

## Overview

The **Strategy Design Pattern** is a behavioral design pattern that defines a **family of algorithms**, encapsulates each one, and makes them **interchangeable at runtime**.

The Strategy pattern lets the algorithm vary independently from the clients that use it.

---

## Problem Statement

In many systems:
- Multiple algorithms are available for a task
- Choosing an algorithm using `if-else` or `switch` logic leads to rigid code
- Adding new algorithms requires modifying existing logic

This violates the Open/Closed Principle.

---

## Solution

The Strategy pattern:
- Encapsulates each algorithm in its own class
- Uses composition instead of conditional logic
- Allows runtime selection and replacement of algorithms

---

## Architecture

### Components

1. **Strategy**
2. **Concrete Strategies**
3. **Context**
4. **Client**

---

### Component Roles

#### 1. Strategy
- Declares a common interface for all algorithms


---

#### 2. Concrete Strategies
- Implement different variants of an algorithm


---

#### 3. Context
- Maintains a reference to a Strategy
- Delegates algorithm execution to the Strategy


---

#### 4. Client
- Chooses and configures the Strategy
- Can switch strategies at runtime

---

## Interaction Flow

1. Client creates a concrete strategy
2. Client injects the strategy into the context
3. Context delegates work to the strategy
4. Client may replace the strategy dynamically

---

## Advantages

### 1. Open/Closed Principle
- New strategies can be added without modifying existing code

---

### 2. Eliminates Conditional Logic
- Replaces large `if-else` or `switch` blocks

---

### 3. Runtime Flexibility
- Algorithms can be switched dynamically

---

### 4. Single Responsibility Principle
- Each strategy encapsulates one algorithm

---

## Trade-offs

- Increases number of classes
- Client must understand differences between strategies
- Slight overhead due to indirection

---

## When to Use Strategy

Use the Strategy pattern when:

- You have multiple interchangeable algorithms
- You want to select algorithms at runtime
- Conditional logic becomes complex
- Algorithms evolve independently

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Strategy | Interchangeable algorithms |
| State | Change behavior based on state |
| Command | Encapsulate requests |
| Template Method | Algorithm skeleton with steps |

---

## Typical Use Cases

- Sorting algorithms
- Compression strategies
- Pricing and discount engines
- Authentication mechanisms
- Routing and pathfinding logic

---

## Summary

The Strategy pattern provides a **clean and extensible** way to vary algorithmic behavior without modifying client code.


