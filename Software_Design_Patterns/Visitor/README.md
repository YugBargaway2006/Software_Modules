# Visitor Design Pattern

**Key principle:**

> Add new behavior without changing the classes of the elements on which it operates.

---


## Overview

The **Visitor Design Pattern** is a behavioral design pattern that lets you **separate algorithms from the objects on which they operate**.

It allows adding new operations to existing object structures **without modifying the objects themselves**.

---

## Problem Statement

In systems with complex object structures:
- Many unrelated operations must be performed on objects
- Adding new operations requires modifying every class
- Classes become bloated with unrelated logic

This violates the Open/Closed Principle.

---

## Solution

The Visitor pattern:
- Extracts operations into separate visitor classes
- Uses **double dispatch** to execute correct logic
- Keeps element classes stable while behavior evolves

---

## Architecture

### Components

1. **Visitor**
2. **Concrete Visitors**
3. **Element**
4. **Concrete Elements**
5. **Client**

---

### Component Roles

#### 1. Visitor
- Declares visit methods for each concrete element


---

#### 2. Concrete Visitor
- Implements behavior for each element type
- Represents a single operation across the structure


---

#### 3. Element
- Declares `accept(visitor)`
- Enables double dispatch


---

#### 4. Concrete Elements
- Implement `accept()`
- Delegate operation to visitor


---

#### 5. Client
- Builds object structure
- Applies visitors to elements

---

## Interaction Flow

1. Client creates a visitor
2. Client passes visitor to element via `accept()`
3. Element calls the appropriate visit method
4. Visitor executes logic specific to element type

---

## Advantages

### 1. Open/Closed Principle (Operations)
- New operations added via new visitors
- No changes to element classes

---

### 2. Separation of Concerns
- Business logic separated from data structures

---

### 3. Centralized Behavior
- Related operations grouped in visitor classes

---

### 4. Supports Double Dispatch
- Correct method resolved based on both visitor and element types

---

## Trade-offs

- Adding new element types requires modifying all visitors
- Increased coupling between visitor and element hierarchy
- More complex design

---

## When to Use Visitor

Use the Visitor pattern when:

- Object structure is stable
- Operations change frequently
- You need to perform many unrelated operations
- You want to avoid polluting element classes

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Visitor | Add operations without modifying classes |
| Strategy | Swap algorithms |
| Command | Encapsulate requests |
| Interpreter | Define grammar and operations |

---

## Typical Use Cases

- Compiler AST processing
- Static code analysis
- Serialization / deserialization
- Reporting engines
- Traversal of complex object graphs

---

## Summary

The Visitor pattern enables **extensible operations** over stable object structures.

