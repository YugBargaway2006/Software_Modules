/*
    Date : 16 June 2026
    Author : Yug Bargaway
    Time Taken : 39 minutes 21 seconds

    PROBLEM: Design a Dynamic Sized Stack
    Design and implement a generic stack data structure. The stack must support Last-In-First-Out (LIFO) operations. 
    Unlike a fixed-size buffer, this stack must automatically grow in capacity when it becomes full.

    Functional Requirements : 
    1. The stack should be initialized with a size. When it gets full, it should double the size.
    2. There should a push, pop operation to simulate LIFO operations
    3. Additonal interfaces for size, top, empty checks of the stack.

    Non-functional Requirements :
    1. Push operation must be amortized O(1). 
    2. Rest interfaces / behaviours must strictly O(1)
    3. Dynamically Allotted array for efficient memory management.
    4. Additonal it should multiple types (template programming)
    5. For better C++ practice, follow rule of 5 semantics (Cons / Dest, Copy, Move)
*/


/*
    Interface / Declarations : stack.hpp 
*/
#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
// Structures for Stack
private:
    T* container;
    size_t max_size;
    size_t stack_size;
    int top_idx;

// Behaviours of Stack
private:
    void increase_size();

public:
    Stack(const size_t sz); 
    ~Stack();   

    Stack(const Stack<T>& obj);
    Stack<T>& operator=(const Stack<T>& obj);

    Stack(Stack<T>&& obj) noexcept;
    Stack<T>& operator=(Stack<T>&& obj);

    void push(const T& obj);
    void pop();
    size_t size() const;
    T& top() const;
    bool empty() const;
};


/*
    Implementations : stack.cpp
*/

// Constructor
template<typename T>
Stack<T>::Stack(const size_t sz) 
    : max_size(sz)
    , stack_size(0)
    , top_idx(-1)
{
    container = new T[max_size];
}

// Destructor
template<typename T>
Stack<T>::~Stack() {
    delete[] container;
}

// Copy Constructor
template<typename T>
Stack<T>::Stack(const Stack<T>& obj) {
    // Deep Copy
    max_size = obj.max_size;
    stack_size = obj.stack_size;
    top_idx = obj.top_idx;

    container = new T[max_size];
    for(size_t idx = 0; idx < stack_size; idx++) {
        container[idx] = obj.container[idx];
    }
}

// Copy Assignment Operator
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj) {
    *this(obj);
    return *this;
}

// Move Constructor
template<typename T>
Stack<T>::Stack(Stack<T>&& obj) noexcept {
    max_size = obj.max_size;
    stack_size = obj.stack_size;
    top_idx = obj.top_idx;
    container = obj.container;

    obj.max_size = 0;
    obj.stack_size = 0;
    obj.top_idx = 0;
    obj.container = nullptr;
}

// Move Assignment 
template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& obj) {
    swap(*this, obj);
    return *this;
}

// Increase Size
template<typename T>
void Stack<T>::increase_size() {
    max_size *= 2;
    T* new_container = new T[max_size];
    for(size_t idx = 0; idx < max_size; idx++) {
        new_container[idx] = container[idx];              // Tip : Use Move Semantics of whatever class T is.
    }
    
    delete[] container;
    container = new_container;
}

// Push Operation
template<typename T>
void Stack<T>::push(const T& obj) {
    if(stack_size == max_size) {
        increase_size();
    }

    container[stack_size] = T;
    stack_size += 1;
    top_idx += 1;
}

// Pop operation
template<typename T>
void Stack<T>::pop() {
    if(stack_size == 0) {
        throw std::runtime_error("Stack is empty. Pop Opeation cannot proceed!");
    }
    top_idx -= 1;
    stack_size -= 1;
}

// Size operation
template<typename T>
size_t Stack<T>::size() const {
    return stack_size;
}

// Top operation
template<typename T>
T& Stack<T>::top() const {
    if(stack_size == 0) {
        throw std::runtime_error("Stack is empty. Top operation cannot proceed!");
    }
    return container[top_idx];
}

// Check empty operation
template<typename T>
bool Stack<T>::empty() const {
    return (stack_size == 0);
}

