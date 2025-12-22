# Command Design Pattern

**Key principle:**

> Encapsulate a request as an object to decouple the sender from the receiver.

---

## Overview

The **Command Design Pattern** is a behavioral design pattern that encapsulates a **request as an object**, thereby allowing parameterization of clients with different requests, queuing or logging of requests, and support for undo/redo operations.

---

## Problem Statement

In many systems:
- A sender (invoker) must trigger actions
- The actual action logic resides elsewhere
- Direct coupling between sender and receiver leads to rigid code

Using direct method calls makes it difficult to:
- Add new operations
- Implement undo/redo
- Queue or log requests

---

## Solution

The Command pattern:
- Wraps a request in a command object
- Decouples the invoker from the receiver
- Allows commands to be stored, queued, or executed later

---

## Architecture

### Components

1. **Command**
2. **Concrete Commands**
3. **Receiver**
4. **Invoker**
5. **Client**

---

### Component Roles

#### 1. Command
- Declares the interface for executing operations


---

#### 2. Concrete Command
- Binds a receiver to an action
- Implements `execute()` by delegating to the receiver


---

#### 3. Receiver
- Performs the actual business logic
- Knows how to carry out the request

---

#### 4. Invoker
- Initiates the request
- Does not know how the request is handled


---

#### 5. Client
- Creates command objects
- Assigns them to invokers

---

## Interaction Flow

1. Client creates a receiver
2. Client creates concrete commands with the receiver
3. Client assigns commands to the invoker
4. Invoker triggers command execution
5. Command calls receiver logic

---

## Advantages

### 1. Loose Coupling
- Invoker and receiver are decoupled
- New commands can be added without modifying invokers

---

### 2. Open/Closed Principle
- Easy to add new commands
- Existing code remains unchanged

---

### 3. Undo / Redo Support
- Commands can store state
- Enables reversible operations

---

### 4. Command Queuing and Logging
- Commands can be queued, scheduled, or logged
- Useful for transactional systems

---

## Trade-offs

- Increases number of classes
- Adds abstraction overhead
- Can be overkill for simple operations

---

## When to Use Command

Use the Command pattern when:

- You want to parameterize objects with operations
- You need undo/redo functionality
- You want to queue or log requests
- You want to decouple UI from business logic

---

## Comparison with Related Patterns

| Pattern | Purpose |
|------|--------|
| Command | Encapsulate requests |
| Chain of Responsibility | Pass request through handlers |
| Mediator | Centralize communication |
| Strategy | Encapsulate algorithms |

---

## Typical Use Cases

- GUI buttons and menus
- Transaction systems
- Job queues and schedulers
- Macro recording
- Remote controls

---

## Summary

The Command pattern enables **flexible and extensible request handling** by turning requests into first-class objects.


