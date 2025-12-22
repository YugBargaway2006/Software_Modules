# Mediator Design Pattern

**Key principle:**

> Objects should communicate through a mediator, not directly with each other.

---

## Overview

The **Mediator Design Pattern** is a behavioral design pattern that defines an object (the mediator) which **encapsulates how a set of objects interact**.

Instead of objects referring to each other directly, they communicate **through the mediator**, reducing coupling.

---

## Problem Statement

In systems with many interacting objects:
- Objects become tightly coupled
- Interaction logic is scattered
- Changes in one object require changes in many others

This leads to complex, fragile, and hard-to-maintain code.

---

## Solution

The Mediator pattern:
- Centralizes communication logic
- Promotes loose coupling between components
- Simplifies object interactions

---

## Architecture

### Components

1. **Mediator**
2. **Concrete Mediator**
3. **Colleague**
4. **Concrete Colleagues**
5. **Client**

---

### Component Roles

#### 1. Mediator
- Declares communication interface
- Coordinates interactions between colleagues


---

#### 2. Concrete Mediator
- Implements coordination logic
- Knows and manages colleague interactions


---

#### 3. Colleague
- Holds a reference to the mediator
- Communicates only through the mediator

---

#### 4. Concrete Colleagues
- Perform their own logic
- Notify mediator instead of interacting directly

---

#### 5. Client
- Creates mediator and colleagues
- Wires objects together

---

## Interaction Flow

1. A colleague triggers an event
2. The colleague notifies the mediator
3. The mediator decides how to react
4. The mediator invokes appropriate actions on other colleagues

---

## Advantages

### 1. Loose Coupling
- Colleagues do not depend on each other
- Dependencies are centralized

---

### 2. Single Responsibility Principle
- Interaction logic is isolated in mediator

---

### 3. Improved Maintainability
- Easier to modify interaction behavior
- Fewer ripple effects

---

### 4. Simplified Colleague Classes
- Colleagues focus only on their own behavior

---

## Trade-offs

- Mediator can become complex ("god object")
- Centralized logic may be harder to debug
- Overhead for simple interaction scenarios

---

## When to Use Mediator

Use the Mediator pattern when:

- Many objects interact in complex ways
- You want to reduce tight coupling
- Communication logic is hard to follow
- UI components interact frequently

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Mediator | Centralize communication |
| Observer | One-to-many notifications |
| Chain of Responsibility | Pass request through handlers |
| Facade | Simplify subsystem interface |

---

## Typical Use Cases

- GUI frameworks (dialogs, forms)
- Chat systems
- Air traffic control systems
- Workflow engines
- Event-driven architectures

---

## Summary

The Mediator pattern provides a **clean and maintainable** way to manage object interactions by centralizing communication logic.


