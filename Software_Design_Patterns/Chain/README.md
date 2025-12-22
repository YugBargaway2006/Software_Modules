# Chain of Responsibility Design Pattern

**Key principle:**

> Give more than one object a chance to handle a request by passing it along a chain.

---

## Overview

The **Chain of Responsibility Design Pattern** is a behavioral design pattern that allows a request to be **passed along a chain of handlers** until one of them handles it.

It decouples the sender of a request from its receivers by allowing multiple objects to process the request without the sender knowing which one will handle it.

---

## Problem Statement

In many systems:
- A request can be handled in multiple ways
- Handling logic is spread across different classes
- Using conditional logic (`if-else`, `switch`) leads to rigid and hard-to-maintain code

Adding new handlers often requires modifying existing logic.

---

## Solution

The Chain of Responsibility pattern:
- Defines a common handler interface
- Links handlers into a chain
- Passes requests along the chain until handled

---

## Architecture

### Components

1. **Handler**
2. **Concrete Handlers**
3. **Client**

---

### Component Roles

#### 1. Handler
- Declares the interface for handling requests
- Maintains a reference to the next handler


---

#### 2. Concrete Handlers
- Decide whether to handle a request
- Forward the request if unable to handle it


---

#### 3. Client
- Sends requests to the first handler
- Does not know which handler will process the request

---

## Interaction Flow

1. Client sends a request to the first handler
2. Handler checks if it can process the request
3. If not, it forwards the request to the next handler
4. The process continues until handled or chain ends

---

## Advantages

### 1. Loose Coupling
- Sender is decoupled from concrete handlers
- Handlers can be reordered or replaced easily

---

### 2. Open/Closed Principle
- New handlers can be added without modifying existing code

---

### 3. Single Responsibility Principle
- Each handler focuses on one type of request

---

### 4. Flexible Request Processing
- Requests can be processed by different handlers dynamically

---

## Trade-offs

- Requests may go unhandled if chain is misconfigured
- Debugging can be harder due to multiple handlers
- Performance overhead for long chains

---

## When to Use Chain of Responsibility

Use this pattern when:

- Multiple objects may handle a request
- You want to avoid tight coupling between sender and receiver
- You want to add or remove handlers dynamically
- Conditional logic becomes complex or repetitive

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Chain of Responsibility | Pass request along handlers |
| Command | Encapsulate a request |
| Mediator | Centralize communication |
| Observer | Notify multiple objects |

---

## Typical Use Cases

- Event handling systems
- Middleware pipelines
- Logging frameworks
- Request validation chains
- Approval workflows

---

## Summary

The Chain of Responsibility pattern enables **flexible and extensible request handling** by passing requests through a chain of independent handlers.


