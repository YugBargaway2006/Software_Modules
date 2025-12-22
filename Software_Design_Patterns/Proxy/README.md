# Proxy Design Pattern

**Key principle:**

> Control access to an object by placing a surrogate in front of it.

---

## Overview

The **Proxy Design Pattern** is a structural design pattern that provides a **surrogate or placeholder** for another object to control access to it.

The proxy implements the same interface as the real object and forwards requests while adding additional behavior.

---

## Problem Statement

Direct access to an object may be undesirable when:
- Object creation is expensive
- Access control is required
- Additional functionality (logging, caching, lazy loading) is needed
- The object resides remotely

Embedding these concerns inside the object violates separation of concerns.

---

## Solution

The Proxy pattern:
- Introduces a proxy class implementing the same interface as the real object
- Controls access to the real object
- Adds behavior before or after delegating requests

---

## Architecture

### Components

1. **Subject**
2. **RealSubject**
3. **Proxy**
4. **Client**

---

### Component Roles

#### 1. Subject
- Declares the common interface
- Client depends only on this abstraction


---

#### 2. RealSubject
- Implements the actual business logic
- Performs the real work


---

#### 3. Proxy
- Maintains a reference to the RealSubject
- Controls access
- Adds auxiliary behavior


---

#### 4. Client
- Works with the Subject interface
- Unaware whether it is using a proxy or real object

---

## Interaction Flow

1. Client calls `request()` on Subject
2. Proxy intercepts the call
3. Proxy performs access checks or preprocessing
4. Proxy forwards the call to RealSubject
5. Proxy performs post-processing if needed
6. Result is returned to the client

---

## Advantages

### 1. Controlled Access
- Enforces security, permissions, or validation

---

### 2. Lazy Initialization
- Delays creation of expensive objects until required

---

### 3. Separation of Concerns
- Cross-cutting concerns are isolated from business logic

---

### 4. Transparency
- Proxy is interchangeable with the real object

---

## Trade-offs

- Adds an extra layer of indirection
- Slight runtime overhead
- Increased complexity if overused

---

## When to Use Proxy

Use the Proxy pattern when:

- You need access control
- Objects are expensive to create
- Lazy loading is required
- Logging, caching, or monitoring is needed
- Working with remote objects

---

## Types of Proxies

- **Virtual Proxy** – Lazy initialization
- **Protection Proxy** – Access control
- **Remote Proxy** – Network-based access
- **Caching Proxy** – Store results
- **Smart Proxy** – Reference counting, logging

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Proxy | Control access to an object |
| Decorator | Add behavior dynamically |
| Adapter | Convert interfaces |
| Facade | Simplify subsystem |

---

## Typical Use Cases

- Access control systems
- Database connection management
- Remote services (RPC)
- Lazy-loaded images
- Logging and monitoring layers

---

## Summary

The Proxy pattern provides a **flexible and controlled** way to manage object access without modifying the original class.


