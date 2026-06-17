/*
    Date : 17 June 2026
    Author : Yug Bargaway

    PROBLEM: Design a Dynamic Double-Ended Queue (Deque)
    Design and implement a generic Double-Ended Queue. A deque is a sequence container that allows fast insertion and deletion 
    at both its beginning and its end.
    Unlike the fixed-size queue, this deque must automatically grow in capacity when it becomes full.

    Functional Requirements : 
    1. There should be constructor to provide initial size of deque
    2. There should be methods for push_front and push_back. If the array is full, it should twice the container size.
    3. Methods for pop_front and pop_back. Throws exception if empty which should be properly handled.
    4. Behaviours to peek to front and back elements of the dequeu
    5. Other methods for size and check empty for the deque.

    Non-functional Requirements :
    1. Dynamically Allotted Array use for efficient memory management.
    2. push operations should be amortized O(1). Rest methods should be strictly O(1) for low-latency operations
    3. It should support multiple types (template programming)
    4. 5. For better C++ practice, follow rule of 5 semantics (Cons / Dest, Copy, Move)
    6. Use C++ Idiom of Getter and Setter to view and change state of deque
*/


/*
    Interface / Declaration : deque.hpp
*/

#include <iostream>
#include <stdexcept>

template<typename T>
class Deque {
// Structures
private:
    T* container;
    int front_idx;
    int back_idx;
    size_t max_size;
    size_t deque_size;

// Behaviours 
private:
    void increase_size();

public:
    Deque(const size_t sz);
    ~Deque();

    Deque(const Deque<T>& obj);
    Deque& operator=(Deque<T> obj);

    Deque(Deque<T>&& obj) noexcept;
    Deque& operator=(Deque<T>&& obj) noexcept;

    void push_front(const T& obj);
    void push_back(const T& obj);
    void pop_front();
    void pop_back();

    const T& front() const;
    const T& back() const;
    size_t size() const;
    bool empty() const;
};


/*
    Implementation : deque.cpp
*/

// Constructor
template<typename T>
Deque<T>::Deque(const size_t sz) 
    : front_idx(1)
    , back_idx(-1)
    , max_size(sz)
    , deque_size(0)
{
    container = new T[max_size];
}

// Destructor
template<typename T>
Deque<T>::~Deque() {
    delete[] container;
}

// Copy Constructor
template<typename T>
Deque<T>::Deque(const Deque<T>& obj) {
    // Deep Copy
    max_size = obj.max_size;
    deque_size = obj.deque_size;
    front_idx = obj.front_idx;
    back_idx = obj.back_idx;

    container = new T[max_size];
    for(size_t idx = 0; idx < max_size; idx++) {
        container[idx] = obj.container[idx];    // We can push the deque to start at 0, but currently maintaining exact copy
    }
}

// Copy Assignment
template<typename T>
Deque<T>& Deque<T>::operator=(Deque<T> obj) {
    swap(*this, obj);
    return *this;
}

// Move Constructor
template<typename T>
Deque<T>::Deque(Deque<T>&& obj) noexcept {
    // Deep Copy
    max_size = obj.max_size;
    deque_size = obj.deque_size;
    front_idx = obj.front_idx;
    back_idx = obj.back_idx;
    container = obj.container;

    obj.max_size = 0;
    obj.deque_size = 0;
    obj.front_idx = 1;
    obj.back_idx = -1;
    obj.container = nullptr;
}

// Move Assignment 
template<typename T>
Deque<T>& Deque<T>::operator=(Deque<T>&& obj) noexcept {
    swap(*this, obj);
    return *this;
}

// Increase Size Operation
template<typename T>
void Deque<T>::increase_size() {
    size_t new_max_size = 2 * max_size;
    T* new_container = new T[new_max_size];

    for(size_t idx = 0; idx < deque_size; idx++) {
        new_container[idx] = std::move(container[(front_idx + idx) % max_size]);
    }
    delete[] container;

    container = new_container;
    max_size = new_max_size;
    front_idx = 0;
    back_idx = deque_size - 1;
}

// Push Front Operation
template<typename T>
void Deque<T>::push_front(const T& obj) {
    if(deque_size == max_size) {
        increase_size();
    }

    front_idx -= 1;
    front_idx = (front_idx + max_size) % max_size;
    container[front_idx] = obj;
    deque_size += 1;

    if(deque_size == 1) back_idx = front_idx;
}

// Push Back Operation
template<typename T>
void Deque<T>::push_back(const T& obj) {
    if(deque_size == max_size) {
        increase_size();
    }

    back_idx += 1;
    back_idx = (back_idx) % max_size;
    container[back_idx] = obj;
    deque_size += 1;

    if(deque_size == 1) front_idx = back_idx;
}

// Pop Front Operation
template<typename T>
void Deque<T>::pop_front() {
    if(deque_size == 0) {
        throw std::runtime_error("Deque is empty. Pop front cannot proceed!");
    }

    front_idx += 1;
    front_idx = (front_idx) % max_size;
    deque_size -= 1;
}

// Pop Back Operation
template<typename T>
void Deque<T>::pop_back() {
    if(deque_size == 0) {
        throw std::runtime_error("Deque is empty. Pop back cannot proceed!");
    }

    back_idx -= 1;
    back_idx = (back_idx + max_size) % max_size;
    deque_size -= 1;
}

// Peek front operation
template<typename T>
const T& Deque<T>::front() const {
    if(deque_size == 0) {
        throw std::runtime_error("Deque is empty. Nothing at front!");
    }

    return container[front_idx];
}

// Peek back operation
template<typename T>
const T& Deque<T>::back() const {
    if(deque_size == 0) {
        throw std::runtime_error("Deque is empty. Nothing at back!");
    }

    return container[back_idx];
}

// View size operation
template<typename T>
size_t Deque<T>::size() const {
    return deque_size;
}

// Check Empty operation
template<typename T>
bool Deque<T>::empty() const {
    return (deque_size == 0);
}