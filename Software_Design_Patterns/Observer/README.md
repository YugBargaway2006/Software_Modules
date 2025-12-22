# Observer Design Pattern

**Key principle:**

> Define a one-to-many dependency so that when one object changes state, all its dependents are notified automatically.

---

## Overview

The **Observer Design Pattern** is a behavioral design pattern that defines a **one-to-many dependency** between objects.  
When the state of one object (the subject) changes, all its dependent objects (observers) are **notified and updated automatically**.

---

## Problem Statement

In many systems:
- Multiple objects depend on the state of another object
- Tight coupling arises when dependents are updated directly
- Changes require modifying multiple classes

This leads to brittle and hard-to-maintain code.

---

## Solution

The Observer pattern:
- Introduces a subscription mechanism
- Allows observers to register and unregister dynamically
- Automatically notifies observers when subject state changes

---

## Architecture

### Components

1. **Subject**
2. **Concrete Subject**
3. **Observer**
4. **Concrete Observers**
5. **Client**

---

### Component Roles

#### 1. Subject
- Maintains a list of observers
- Provides methods to attach/detach observers
- Notifies observers of state changes


---

#### 2. Concrete Subject
- Stores subject state
- Triggers notifications on state change


---

#### 3. Observer
- Declares update interface
- Receives notifications


---

#### 4. Concrete Observers
- Implement update behavior
- React to subject state changes


---

#### 5. Client
- Creates subject and observers
- Registers observers with subject

---

## Interaction Flow

1. Observers subscribe to the subject
2. Subject state changes
3. Subject calls `notify()`
4. All registered observers receive updates
5. Observers react independently

---

## Advantages

### 1. Loose Coupling
- Subject does not depend on concrete observers
- Observers can be added or removed freely

---

### 2. Open/Closed Principle
- New observers can be added without modifying subject code

---

### 3. Dynamic Relationships
- Observers can subscribe/unsubscribe at runtime

---

### 4. Separation of Concerns
- Subject manages state
- Observers manage reactions

---

## Trade-offs

- Notification order is not guaranteed
- Potential performance cost with many observers
- Risk of cascading updates if misused

---

## When to Use Observer

Use the Observer pattern when:

- Multiple objects must react to state changes
- Event-driven behavior is required
- You want to avoid tight coupling
- Publish–subscribe semantics fit the problem

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Observer | One-to-many notifications |
| Mediator | Centralized communication |
| Command | Encapsulate requests |
| Chain of Responsibility | Pass requests through handlers |

---

## Typical Use Cases

- Event handling systems
- GUI frameworks
- Notification services
- Data-binding mechanisms
- Real-time monitoring systems

---

## Summary

The Observer pattern provides a **flexible and decoupled** way to propagate state changes.


