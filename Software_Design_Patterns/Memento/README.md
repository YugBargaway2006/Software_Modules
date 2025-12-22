# Memento Design Pattern

**Key principle:**

> Capture and restore object state without exposing its internal structure.

---

## Overview

The **Memento Design Pattern** is a behavioral design pattern that allows capturing and externalizing an object's **internal state** so that the object can be restored to this state later, **without violating encapsulation**.

It is commonly used to implement **undo/redo** functionality.

---

## Problem Statement

In many applications:
- Objects evolve over time
- You need to restore previous states
- Exposing internal state breaks encapsulation

Saving state directly inside external objects can tightly couple components and compromise design integrity.

---

## Solution

The Memento pattern:
- Captures the internal state of an object in a separate memento object
- Stores mementos externally
- Restores state without exposing internals

---

## Architecture

### Components

1. **Originator**
2. **Memento**
3. **Caretaker**
4. **Client**

---

### Component Roles

#### 1. Originator
- The object whose state must be saved and restored
- Creates and consumes mementos


---

#### 2. Memento
- Stores the internal state of the originator
- State is opaque to caretakers


---

#### 3. Caretaker
- Manages mementos
- Never inspects or modifies memento contents


---

#### 4. Client
- Initiates save and restore operations
- Coordinates originator and caretaker

---

## Interaction Flow

1. Originator creates a memento containing its current state
2. Caretaker stores the memento
3. Originator changes its state
4. Client requests restoration
5. Originator restores state from memento

---

## Advantages

### 1. Preserves Encapsulation
- Internal state is not exposed
- Only originator can access state details

---

### 2. Simplifies Undo/Redo
- Clean and reliable state restoration
- Supports multiple levels of undo

---

### 3. Separation of Concerns
- Caretaker manages history
- Originator manages state logic

---

## Trade-offs

- Increased memory usage
- Managing large state snapshots can be expensive
- Caretaker complexity grows with history size

---

## When to Use Memento

Use the Memento pattern when:

- Undo/redo functionality is required
- Object state must be restored reliably
- Encapsulation must be preserved
- State changes are significant and frequent

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Memento | Restore object state |
| Command | Encapsulate actions (often used with undo) |
| Prototype | Clone object state |
| Snapshot | Conceptual variant of memento |

---

## Typical Use Cases

- Text editors (undo/redo)
- Graphic design tools
- Transaction rollback systems
- Game save/load systems
- Configuration versioning

---

## Summary

The Memento pattern provides a **safe and encapsulated mechanism** for saving and restoring object state.


