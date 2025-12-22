# Iterator Design Pattern

**Key principle:**

> Separate traversal logic from collection structure.

---

## Overview

The **Iterator Design Pattern** is a behavioral design pattern that provides a way to **access elements of a collection sequentially** without exposing its underlying representation.

It decouples traversal logic from the collection itself.

---

## Problem Statement

Collections may store elements in different ways:
- Arrays
- Lists
- Trees
- Graphs

Exposing internal structures leads to:
- Tight coupling
- Fragile client code
- Violation of encapsulation

---

## Solution

The Iterator pattern:
- Defines a common traversal interface
- Encapsulates iteration logic in a separate object
- Allows multiple traversal strategies without changing the collection

---

## Architecture

### Components

1. **Iterator**
2. **Concrete Iterator**
3. **Aggregate**
4. **Concrete Aggregate**
5. **Client**

---

### Component Roles

#### 1. Iterator
- Declares traversal operations


---

#### 2. Concrete Iterator
- Implements traversal over a specific collection
- Keeps track of the current position


---

#### 3. Aggregate
- Declares method to create an iterator


---

#### 4. Concrete Aggregate
- Stores collection elements
- Returns an appropriate iterator

---

#### 5. Client
- Uses the iterator interface
- Does not depend on collection internals

---

## Interaction Flow

1. Client requests an iterator from the aggregate
2. Client uses `hasNext()` and `next()` to traverse
3. Iterator accesses collection elements internally
4. Collection structure remains hidden

---

## Advantages

### 1. Encapsulation
- Internal representation is hidden from clients

---

### 2. Single Responsibility Principle
- Collection manages storage
- Iterator manages traversal

---

### 3. Multiple Traversal Strategies
- Multiple iterators can coexist
- Different iteration orders are possible

---

### 4. Simplified Client Code
- Uniform traversal interface for different collections

---

## Trade-offs

- Introduces additional classes
- Slight overhead for iterator objects
- Can duplicate functionality already provided by language constructs

---

## When to Use Iterator

Use the Iterator pattern when:

- You want to hide collection internals
- Multiple traversal strategies are required
- Collections have complex internal structures
- You want a uniform traversal API

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Iterator | Sequential access |
| Composite | Tree structures |
| Visitor | Add operations to structures |
| Command | Encapsulate requests |

---

## Typical Use Cases

- Collection traversal APIs
- Database result iteration
- Tree and graph traversal
- Custom container libraries

---

## Note on C++

C++ STL already provides iterators (`begin()`, `end()`), which are a **native implementation** of this pattern.  
Use custom iterators when traversal logic is non-trivial or domain-specific.

---

## Summary

The Iterator pattern provides a **clean and extensible** way to traverse collections while preserving encapsulation.


