# State Design Pattern

**Key principle:**

> Allow an object to change its behavior when its internal state changes.

---

## Overview

The **State Design Pattern** is a behavioral design pattern that allows an object to **alter its behavior when its internal state changes**.  
The object appears to change its class at runtime.

State-specific behavior is encapsulated into separate state classes.

---

## Problem Statement

In many systems:
- An object behaves differently based on its internal state
- Behavior is implemented using large `if-else` or `switch` statements
- Adding new states makes code fragile and hard to maintain

This results in tightly coupled and error-prone logic.

---

## Solution

The State pattern:
- Encapsulates each state into a separate class
- Delegates behavior to the current state object
- Allows state transitions at runtime

---

## Architecture

### Components

1. **Context**
2. **State (Interface / Abstract Class)**
3. **Concrete States**
4. **Client**

---

### Component Roles

#### 1. State
- Declares interface for state-specific behavior


---

#### 2. Concrete States
- Implement behavior associated with a particular state
- Can trigger state transitions


---

#### 3. Context
- Maintains a reference to the current state
- Delegates requests to the state object


---

#### 4. Client
- Interacts with the context
- Does not directly manage state transitions

---

## Interaction Flow

1. Client calls a method on the context
2. Context delegates behavior to the current state
3. State executes logic
4. State may change the context’s state

---

## Advantages

### 1. Eliminates Conditional Logic
- Replaces large `if-else` or `switch` statements

---

### 2. Open/Closed Principle
- New states can be added without modifying existing code

---

### 3. Single Responsibility Principle
- Each state encapsulates its own behavior

---

### 4. Cleaner and More Maintainable Code
- Behavior is localized and explicit

---

## Trade-offs

- Increases number of classes
- State transitions may be harder to trace
- Overhead for simple state machines

---

## When to Use State

Use the State pattern when:

- Object behavior depends on internal state
- State transitions are frequent
- Conditional logic becomes complex
- You want to model a finite state machine

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| State | Change behavior with state |
| Strategy | Swap algorithms |
| Command | Encapsulate requests |
| State + FSM | Explicit state machines |

---

## Typical Use Cases

- Workflow engines
- Network protocol states
- Media players
- Game character behavior
- Order processing systems

---

## Summary

The State pattern enables **dynamic behavior changes** by delegating logic to state objects.


