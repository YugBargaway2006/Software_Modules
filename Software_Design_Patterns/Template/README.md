# Template Method Design Pattern


**Key principle:**

> Define the invariant parts of an algorithm once, and let subclasses implement the variable parts.

---

## Overview

The **Template Method Design Pattern** is a behavioral design pattern that defines the **skeleton of an algorithm** in a base class while allowing subclasses to redefine certain steps of the algorithm **without changing its structure**.

The overall flow is fixed, but specific steps are customizable.

---

## Problem Statement

In many systems:
- Multiple classes follow the same high-level algorithm
- Only certain steps differ
- Copying and modifying code leads to duplication and inconsistency

Using inheritance with duplicated logic violates maintainability principles.

---

## Solution

The Template Method pattern:
- Defines the algorithm structure in a base class
- Delegates variable steps to subclasses
- Preserves a consistent execution order

---

## Architecture

### Components

1. **Abstract Class (Template)**
2. **Concrete Subclasses**
3. **Client**

---

### Component Roles

#### 1. Abstract Class
- Defines the template method
- Implements invariant parts of the algorithm
- Declares abstract methods for customizable steps
- May provide optional hook methods


---

#### 2. Concrete Subclasses
- Implement required steps
- Optionally override hooks
- Cannot change algorithm order


---

#### 3. Client
- Works with base class interface
- Relies on polymorphism

---

## Interaction Flow

1. Client calls the template method
2. Template method executes steps in fixed order
3. Subclass implementations are invoked polymorphically
4. Algorithm completes with consistent structure

---

## Advantages

### 1. Code Reuse
- Common logic is centralized
- Eliminates duplication

---

### 2. Enforces Algorithm Structure
- Prevents subclasses from altering critical flow

---

### 3. Open/Closed Principle
- New behavior added via subclasses without modifying template

---

### 4. Single Responsibility Principle
- Algorithm orchestration and step implementation are separated

---

## Trade-offs

- Inflexible algorithm structure
- Overuse of inheritance
- Harder to modify step order

---

## When to Use Template Method

Use the Template Method pattern when:

- Algorithms share a common structure
- Only specific steps vary
- Execution order must be enforced
- Code duplication is present

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Template Method | Algorithm skeleton |
| Strategy | Algorithm replacement |
| Factory Method | Object creation delegation |
| State | Behavior changes with state |

---

## Typical Use Cases

- Data processing pipelines
- Framework lifecycle methods
- Build systems
- Testing frameworks
- Parsing and serialization workflows

---

## Summary

The Template Method pattern provides a **structured and maintainable** way to define algorithms with customizable steps.

