# Composite Design Pattern

**Key principle:**

> Compose objects into tree structures and treat them uniformly.

---

## Overview

The **Composite Design Pattern** is a structural design pattern that allows you to treat **individual objects (leaves)** and **compositions of objects (composites)** uniformly.

It is ideal for representing **tree-like hierarchical structures**.

---

## Problem Statement

In many systems, objects naturally form hierarchies, such as:
- File systems
- UI component trees
- Organization charts
- Expression trees

Without a common abstraction, clients must distinguish between simple objects and collections, leading to complex and fragile code.

---

## Solution

The Composite pattern:
- Defines a common interface for both leaf and composite objects
- Allows clients to treat single objects and object groups uniformly
- Organizes objects into tree structures

---

## Architecture

### Components

1. **Component**
2. **Leaf**
3. **Composite**
4. **Client**

---

### Component Roles

#### 1. Component
- Declares the common interface
- Optionally defines child management operations


---

#### 2. Leaf
- Represents individual objects
- Implements the base behavior


---

#### 3. Composite
- Represents objects that can have children
- Implements child-related operations
- Delegates work to its children


---

#### 4. Client
- Works with Component interface
- Does not need to distinguish between leaf and composite

---

## Interaction Flow

1. Client builds a tree of components
2. Client calls `operation()` on the root
3. Composite forwards the call to its children
4. Leaf performs the actual operation

---

## Advantages

### 1. Uniformity
- Clients treat individual and composite objects identically

---

### 2. Open/Closed Principle
- New component types can be added without changing client code

---

### 3. Simplified Client Code
- Eliminates conditional logic for object type checks

---

### 4. Natural Tree Modeling
- Perfect fit for hierarchical data structures

---

## Trade-offs

- Can make type constraints harder to enforce
- Child management methods may not apply to all components
- Risk of overly generic interfaces

---

## When to Use Composite

Use Composite when:

- You need to represent part-whole hierarchies
- Clients should ignore differences between single and grouped objects
- Tree structures dominate the domain

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Composite | Treat objects and compositions uniformly |
| Decorator | Add behavior dynamically |
| Flyweight | Share common object state |
| Visitor | Add operations without changing structure |

---

## Typical Use Cases

- File system directories and files
- UI layout systems
- Organizational hierarchies
- Mathematical expression trees
- Scene graphs in game engines

---

## Summary

The Composite pattern provides a **clean and scalable** way to model hierarchical structures.


