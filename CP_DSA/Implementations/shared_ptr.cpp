/*
    Date : 18 June 2026
    Author : Yug Bargaway

    PROBLEM: Design a Custom Shared Pointer (shared_ptr)
    Design and implement a generic smart pointer that retains shared ownership of an object through a pointer. Multiple `Shared_ptr` instances may own the same underlying raw pointer.

    Functional Requirements : 
    1. There should be a constructor taking a raw pointer and a destructor managing memory.
    2. Must fully support the Rule of Five (Copy/Move semantics).
    3. Overloaded dereference (*) and member access (->) operators.
    4. Method to view the number of shared owners (count).
    5. Reset pointer to safely release current ownership and take a new pointer.

    Non-functional Requirements :
    1. Dynamic allocation of a separate Control Block for efficient tracking.
    2. Thread-safe reference counting using std::atomic so multiple pointers can be created/destroyed concurrently.
    3. Zero memory leaks: Both the data block and control block must be deleted when the count reaches 0.
*/

/*
    Interface / Declaration : shared_ptr.hpp
*/

#include <iostream>
#include <stdexcept>
#include <utility>
#include <atomic>

template<typename T>
class Shared_ptr {
// Structures
private:
    T* data_ptr;
    std::atomic<size_t>* counter;

// Behaviours
private:
    void release();

public:
    Shared_ptr(T* ptr = nullptr);
    ~Shared_ptr();

    Shared_ptr(const Shared_ptr<T>& ptr);
    Shared_ptr<T>& operator=(Shared_ptr<T> ptr);

    Shared_ptr(Shared_ptr<T>&& ptr) noexcept;
    Shared_ptr<T>& operator=(Shared_ptr<T>&& ptr) noexcept;
    
    T& operator*() const;
    T* operator->() const;

    size_t count() const;
    T* get() const;
    void reset(T* ptr = nullptr);
};


/*
    Implementation : shared_ptr.cpp
*/

// Helper: Safely release resources
template<typename T>
void Shared_ptr<T>::release() {
    if (counter != nullptr) {
        if (counter->fetch_sub(1) == 1) {
            delete data_ptr;
            delete counter;
        }
    }
}

// Constructor
template<typename T>
Shared_ptr<T>::Shared_ptr(T* ptr) 
    : data_ptr(ptr)
    , counter(ptr != nullptr ? new std::atomic<size_t>(1) : nullptr)
{
}

// Destructor
template<typename T>
Shared_ptr<T>::~Shared_ptr() {
    release();
}

// Copy Constructor
template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr<T>& ptr) 
    : data_ptr(ptr.data_ptr)
    , counter(ptr.counter)
{
    if (counter != nullptr) {
        counter->fetch_add(1);
    }
}

// Copy Assignment
template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr<T> ptr) {
    std::swap(data_ptr, ptr.data_ptr);
    std::swap(counter, ptr.counter);
    return *this;
}

// Move Constructor
template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T>&& ptr) noexcept 
    : data_ptr(ptr.data_ptr)
    , counter(ptr.counter) 
{
    ptr.data_ptr = nullptr;
    ptr.counter = nullptr;
}

// Move Assignment
template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr<T>&& ptr) noexcept {
    if (this != &ptr) {
        release();

        data_ptr = ptr.data_ptr;
        counter = ptr.counter;

        ptr.data_ptr = nullptr;
        ptr.counter = nullptr;
    }
    return *this;
}

// Dereference operator
template<typename T>
T& Shared_ptr<T>::operator*() const {
    if (data_ptr == nullptr) {
        throw std::runtime_error("Attempted to dereference a null Shared_ptr");
    }
    return *data_ptr;
}

// Member Access Operator
template<typename T>
T* Shared_ptr<T>::operator->() const {
    return data_ptr;
}

// Get count method
template<typename T>
size_t Shared_ptr<T>::count() const {
    return counter != nullptr ? counter->load() : 0;
}

// Get internal pointer method
template<typename T>
T* Shared_ptr<T>::get() const {
    return data_ptr;
}

// Reset method
template<typename T>
void Shared_ptr<T>::reset(T* ptr) {
    release();
    
    data_ptr = ptr;
    counter = (ptr != nullptr) ? new std::atomic<size_t>(1) : nullptr;
}