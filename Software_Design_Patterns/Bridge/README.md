# Bridge Design Pattern

**Key principle:**

> Separate what varies from what stays the same.

---

## Overview

The **Bridge Design Pattern** is a structural design pattern that **decouples an abstraction from its implementation**, allowing the two to vary independently.

It prevents a combinatorial explosion of subclasses by favoring **composition over inheritance**.

---

## Problem Statement

When both:
- An abstraction (e.g., Shape)
- And its implementation (e.g., Renderer)

need to evolve independently, inheritance leads to a class explosion:


This approach is not scalable.

---

## Solution

The Bridge pattern:
- Separates abstraction and implementation into two hierarchies
- Connects them via composition
- Allows independent extension of both dimensions

---

## Architecture

### Components

1. **Abstraction**
2. **Refined Abstraction**
3. **Implementor**
4. **Concrete Implementors**
5. **Client**

---

### Component Roles

#### 1. Implementor
- Defines the interface for implementation classes
- Does not depend on abstraction details


---

#### 2. Concrete Implementors
- Provide platform- or strategy-specific behavior


---

#### 3. Abstraction
- Defines high-level operations
- Maintains a reference to an Implementor


---

#### 4. Refined Abstractions
- Extend abstraction without touching implementation


---

#### 5. Client
- Works with abstraction only
- Can swap implementations at runtime

---

## Interaction Flow

1. Client creates an Implementor
2. Client injects it into an Abstraction
3. Abstraction delegates work to Implementor
4. Both hierarchies evolve independently

---

## Advantages

### 1. Independent Extensibility
- Add new abstractions without modifying implementations
- Add new implementations without touching abstractions

---

### 2. Avoids Class Explosion
- Eliminates inheritance-based combinations

---

### 3. Runtime Flexibility
- Implementations can be switched dynamically

---

### 4. Improved Maintainability
- Clear separation of responsibilities

---

## Trade-offs

- Adds an extra level of indirection
- Slightly more complex initial design
- Overkill for small or static systems

---

## When to Use Bridge

Use Bridge when:

- Abstraction and implementation change independently
- You want to avoid subclass explosion
- You need runtime implementation switching
- You want to follow composition over inheritance

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Bridge | Decouple abstraction from implementation |
| Adapter | Make incompatible interfaces work |
| Decorator | Add behavior dynamically |
| Facade | Simplify subsystem interface |

---

## Typical Use Cases

- Graphics rendering engines
- Cross-platform UI frameworks
- Device drivers
- Database abstraction layers
- Messaging systems

---

## Summary

The Bridge pattern provides **structural flexibility** by splitting responsibilities across two hierarchies.


