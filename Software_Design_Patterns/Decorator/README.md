# Decorator Design Pattern

**Key principle:**

> Attach additional responsibilities to objects dynamically.

---

## Overview

The **Decorator Design Pattern** is a structural design pattern that allows behavior to be **added to individual objects dynamically** without modifying their class.

It provides a flexible alternative to subclassing for extending functionality.

---

## Problem Statement

When you want to add responsibilities to objects, using inheritance can lead to:
- Subclass explosion
- Rigid class hierarchies
- Poor runtime flexibility

Example:

---

## Solution

The Decorator pattern:
- Wraps objects in decorator classes
- Decorators implement the same interface as the wrapped object
- Behavior is added before or after delegating to the wrapped object

---

## Architecture

### Components

1. **Component**
2. **Concrete Component**
3. **Decorator**
4. **Concrete Decorators**
5. **Client**

---

### Component Roles

#### 1. Component
- Defines the common interface
- Both concrete components and decorators implement it


---

#### 2. Concrete Component
- The original object
- Implements the base behavior

---

#### 3. Decorator
- Maintains a reference to a Component
- Delegates calls to the wrapped object


---

#### 4. Concrete Decorators
- Add responsibilities dynamically
- Can be stacked in any order


---

#### 5. Client
- Works with Component interface
- Can combine decorators freely

---

## Interaction Flow

1. Client creates a concrete component
2. Client wraps it with one or more decorators
3. Client calls operations on the decorated object
4. Each decorator adds behavior and forwards the call

---

## Advantages

### 1. Open/Closed Principle
- Behavior is extended without modifying existing classes

---

### 2. Runtime Flexibility
- Responsibilities can be added or removed dynamically

---

### 3. Avoids Subclass Explosion
- Eliminates combinatorial class growth

---

### 4. Single Responsibility Principle
- Each decorator focuses on one responsibility

---

## Trade-offs

- Many small objects can be created
- Debugging can be harder due to deep wrapping
- Order of decorators matters

---

## When to Use Decorator

Use Decorator when:

- You want to add behavior dynamically
- Inheritance becomes unwieldy
- Behavior combinations are needed at runtime
- You want fine-grained responsibility composition

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Decorator | Add behavior dynamically |
| Adapter | Make incompatible interfaces compatible |
| Facade | Simplify subsystem interface |
| Composite | Tree structure of objects |

---

## Typical Use Cases

- Logging frameworks
- Stream I/O (e.g., `std::iostream` wrappers)
- GUI widgets
- Middleware layers
- Authorization and validation pipelines

---

## Summary

The Decorator pattern provides a **powerful and flexible** mechanism for extending object behavior at runtime.


