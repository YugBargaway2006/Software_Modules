# Factory Method Design Pattern  
## Architecture, Advantages, and Design Choice

---

**Key principle:**

> Defer object creation to subclasses while keeping client code stable.

---

## Overview

The **Factory Method Design Pattern** is a creational design pattern that defines an interface for creating objects, while allowing subclasses to decide **which concrete class to instantiate**.

The core intent is to **decouple object creation from object usage**, enabling extensibility, maintainability, and clean separation of concerns.

---

## Architecture

### High-Level Structure

The pattern is composed of the following components:

1. **Product (Interface / Abstract Class)**
2. **Concrete Products**
3. **Creator (Abstract Factory)**
4. **Concrete Creators**
5. **Client**

---

### Component Breakdown

#### 1. Product
- Declares the common interface for all objects that the factory can create.
- Client and creator depend only on this abstraction.


---

#### 2. Concrete Products
- Implement the `Product` interface.
- Contain variant-specific behavior.

Each concrete product represents a distinct implementation of the same abstraction.

---

#### 3. Creator (Factory Base Class)
- Declares the **factory method** responsible for object creation.
- Contains business logic that works with `Product` objects.
- Does not know the concrete product types.


---

#### 4. Concrete Creators
- Override the factory method.
- Decide which concrete product to instantiate.


---

#### 5. Client
- Works only with `Creator` and `Product` abstractions.
- Remains completely unaware of concrete implementations.

---

### Interaction Flow

1. Client instantiates a concrete creator.
2. Client invokes a method on the creator.
3. Creator calls `createProduct()`.
4. Concrete creator returns a concrete product.
5. Creator uses the product via the `Product` interface.

---

## Advantages

### 1. Loose Coupling
- Client code is independent of concrete product classes.
- Implementation changes do not propagate to client logic.

---

### 2. Open/Closed Principle
- New products can be introduced by:
  - Adding a new concrete product
  - Adding a new concrete creator
- Existing code remains unchanged.

---

### 3. Single Responsibility Principle
- Object creation logic is isolated from business logic.
- Each class has a focused responsibility.

---

### 4. Improved Testability
- Custom creators can return mock or stub products.
- Enables clean unit testing without modifying production code.

---

### 5. Scalability
- Ideal for large systems that evolve over time.
- Common in extensible frameworks and engines.

---

## Why Choose Factory Method?

### When It Is the Right Choice

Use the Factory Method pattern when:

- The exact type of object is unknown at compile time.
- Object creation depends on runtime conditions.
- New product types are expected in the future.
- You want to eliminate large `if-else` or `switch` blocks.
- You want to enforce a consistent creation contract.

---

### Comparison with Related Patterns

| Pattern | When to Use |
|------|------------|
| Factory Method | Single product hierarchy, subclass-based creation |
| Abstract Factory | Multiple related product families |
| Builder | Step-by-step construction of complex objects |
| Prototype | Object creation via cloning |

---

## Trade-offs

- Increases the number of classes.
- Adds abstraction overhead.
- Can be excessive for small or static systems.

---

## Typical Use Cases

- UI frameworks (buttons, dialogs)
- Game engines (weapons, characters)
- Logging systems (file, console, remote)
- Database connectors
- Plugin and extension architectures

---

## Summary

The Factory Method pattern provides a **clean, extensible, and maintainable** approach to object creation.

It allows systems to grow without requiring modifications to existing client code.


