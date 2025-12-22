# Flyweight Design Pattern

**Key principle:**

> Share what is common, externalize what varies.

---

## Overview

The **Flyweight Design Pattern** is a structural design pattern that minimizes memory usage by **sharing common object state** among multiple objects.

It is particularly useful when a large number of fine-grained objects are required and most of their state can be shared.

---

## Problem Statement

In systems that create many similar objects:
- Memory consumption becomes excessive
- Performance degrades due to object creation overhead

Examples include:
- Characters in a text editor
- Particles in a game engine
- Tiles in a map
- UI elements with shared styles

---

## Solution

The Flyweight pattern:
- Splits object state into **intrinsic (shared)** and **extrinsic (context-specific)**
- Stores intrinsic state in shared flyweight objects
- Supplies extrinsic state from the client at runtime

---

## Architecture

### Components

1. **Flyweight**
2. **Concrete Flyweight**
3. **Flyweight Factory**
4. **Client**

---

### Component Roles

#### 1. Flyweight
- Declares an interface for flyweight objects
- Accepts extrinsic state as parameters


---

#### 2. Concrete Flyweight
- Stores intrinsic (shared) state
- Implements flyweight behavior


---

#### 3. Flyweight Factory
- Creates and manages flyweight objects
- Ensures shared instances are reused


---

#### 4. Client
- Maintains extrinsic state
- Uses flyweights provided by the factory

---

## Interaction Flow

1. Client requests a flyweight from the factory
2. Factory returns an existing instance or creates one
3. Client supplies extrinsic state during operation calls
4. Flyweight uses both intrinsic and extrinsic state

---

## Advantages

### 1. Reduced Memory Usage
- Shared objects dramatically lower memory footprint

---

### 2. Improved Performance
- Fewer object allocations
- Better cache utilization

---

### 3. Scalable Object Management
- Efficient handling of millions of similar objects

---

## Trade-offs

- Increased complexity due to state separation
- Clients must manage extrinsic state
- Not suitable when objects have little shared data

---

## When to Use Flyweight

Use the Flyweight pattern when:

- You need to create many similar objects
- Memory usage is a critical concern
- Object state can be cleanly divided into shared and non-shared parts

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Flyweight | Share common object state |
| Singleton | One global instance |
| Composite | Tree of objects |
| Decorator | Add behavior dynamically |

---

## Typical Use Cases

- Text rendering systems
- Game engines (particles, terrain tiles)
- GUI frameworks
- Object pools and caches
- Rendering and simulation engines

---

## Summary

The Flyweight pattern provides an **efficient memory-optimization strategy** by sharing intrinsic object state across many instances.


