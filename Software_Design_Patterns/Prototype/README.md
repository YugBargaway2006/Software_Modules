# Prototype Design Pattern

**Key idea:**

> Create new objects by cloning a prototype instead of constructing them from scratch.

---

## Overview

The **Prototype Design Pattern** is a creational design pattern that allows objects to be created by **cloning existing instances**, rather than instantiating new objects directly.

This pattern is especially useful when:
- Object creation is expensive
- Objects share common configuration
- Runtime object creation is required without knowing concrete classes

---

## Problem Statement

Creating complex objects using constructors can be:
- Costly (deep initialization, heavy setup)
- Tightly coupled to concrete classes
- Difficult when the exact type is only known at runtime

---

## Solution

The Prototype pattern:
- Introduces a common cloning interface
- Uses existing objects as templates
- Creates new objects by copying an existing instance

---

## Architecture

### Components

1. **Prototype (Interface / Abstract Class)**
2. **Concrete Prototype**
3. **Client**

---

### Component Roles

#### 1. Prototype
- Declares a `clone()` method
- Ensures all concrete prototypes support copying


---

#### 2. Concrete Prototype
- Implements the cloning logic
- Performs deep or shallow copy as required


---

#### 3. Client
- Creates new objects by cloning prototypes
- Does not depend on concrete class constructors

---

## Interaction Flow

1. Client holds a prototype instance
2. Client calls `clone()` on the prototype
3. A new object is created by copying the prototype
4. Client customizes the cloned object if needed

---

## Advantages

### 1. Reduced Object Creation Cost
- Avoids expensive constructor logic
- Faster object creation via copying

---

### 2. Decoupling from Concrete Classes
- Client depends only on the prototype interface
- No direct `new` calls for concrete types

---

### 3. Runtime Object Creation
- New object types can be created dynamically
- Useful when types are unknown at compile time

---

### 4. Simplified Object Initialization
- Default state already exists in prototype
- Only differences need to be modified

---

## Trade-offs

- Requires correct implementation of copy logic
- Deep copy handling can be complex
- Cloning large object graphs may be costly

---

## When to Use Prototype

Use the Prototype pattern when:

- Object creation is expensive
- Objects have similar initial states
- You want to avoid subclass explosion
- Object types must be decided at runtime

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Prototype | Clone existing objects |
| Factory Method | Create objects via subclasses |
| Builder | Step-by-step construction |
| Abstract Factory | Create families of objects |

---

## Typical Use Cases

- Game object spawning
- Configuration templates
- Document editors (copy/paste)
- Graphical objects
- Caching and object pools

---

## Summary

The Prototype pattern provides a **flexible and efficient** way to create objects by copying existing ones.


