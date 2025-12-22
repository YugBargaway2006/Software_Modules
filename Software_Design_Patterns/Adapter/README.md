# Adapter Design Pattern

**Key principle:**

> Convert the interface of a class into another interface clients expect.

---

## Overview

The **Adapter Design Pattern** is a structural design pattern that allows objects with **incompatible interfaces** to work together.

It acts as a **bridge between the client and an existing class**, converting one interface into another that the client expects.

---

## Problem Statement

In real-world systems, you often encounter:
- Legacy code with fixed interfaces
- Third-party libraries with incompatible APIs
- Systems that cannot be modified directly

Direct integration is impossible without changing existing code, which may be risky or infeasible.

---

## Solution

The Adapter pattern:
- Wraps an existing class (Adaptee)
- Exposes a new interface (Target) expected by the client
- Translates calls from the client into calls the adaptee understands

---

## Architecture

### Components

1. **Target**
2. **Adaptee**
3. **Adapter**
4. **Client**

---

### Component Roles

#### 1. Target
- Defines the interface expected by the client
- Client code depends only on this abstraction


---

#### 2. Adaptee
- Existing class with incompatible interface
- Cannot or should not be modified


---

#### 3. Adapter
- Implements the Target interface
- Internally uses an Adaptee
- Translates requests


---

#### 4. Client
- Uses objects through the Target interface
- Unaware of the adaptee’s existence

---

## Interaction Flow

1. Client calls `request()` on Target
2. Adapter receives the call
3. Adapter translates it to `specificRequest()`
4. Adaptee processes the request
5. Result is returned to the client

---

## Advantages

### 1. Open/Closed Principle
- Existing code remains unchanged
- New adapters can be added without modifying clients

---

### 2. Reusability
- Enables reuse of legacy or third-party code
- Avoids code duplication

---

### 3. Separation of Concerns
- Translation logic is isolated
- Client remains clean and stable

---

### 4. Improved Maintainability
- Interface changes are localized to adapters
- Reduces ripple effects across the system

---

## Trade-offs

- Adds an extra layer of abstraction
- Can increase code complexity if overused
- Multiple adapters may be needed for many incompatible interfaces

---

## When to Use Adapter

Use the Adapter pattern when:

- You need to integrate legacy code
- Third-party APIs do not match your system’s interfaces
- You cannot modify existing classes
- You want to decouple client code from external dependencies

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Adapter | Make incompatible interfaces work together |
| Facade | Simplify a complex subsystem |
| Decorator | Add behavior dynamically |
| Bridge | Separate abstraction from implementation |

---

## Common Variations

- **Object Adapter** (composition – most common, shown here)
- **Class Adapter** (inheritance-based, limited in C++)
- **Two-way Adapter**

---

## Typical Use Cases

- Legacy system integration
- Wrapping third-party libraries
- API version compatibility
- Hardware or OS abstraction layers

---

## Summary

The Adapter pattern provides a **safe and flexible** way to integrate incompatible components without modifying existing code.

