/*
    Date : 18 June 2026
    Author : Yug Bargaway

    PROBLEM: Design a Custom Unique Pointer (unique_ptr)
    Design and implement a generic smart pointer that retains strictly EXCLUSIVE ownership of an object through a pointer. Two `Unique_ptr` instances cannot own the same underlying raw pointer.

    Functional Requirements : 
    1. Explicit constructor taking a raw pointer, and a destructor to manage memory.
    2. Rule of Five: Copying is explicitly forbidden. Moving transfers ownership safely.
    3. Overloaded dereference (*) and member access (->) operators.
    4. Methods to view raw pointer (get), relinquish ownership (release), and take new ownership (reset).

    Non-functional Requirements :
    1. Zero overhead: The pointer must have the exact same memory footprint as a raw pointer.
    2. Zero memory leaks: The managed object must be destroyed exactly once.
*/

/*
    Interface / Declaration : unique_ptr.hpp
*/

#include <iostream>
#include <stdexcept>
#include <utility>

template<typename T>
class Unique_ptr {
// Structures
private:
    T* data_ptr;

// Behaviours
public:
    Unique_ptr(T* ptr = nullptr);
    ~Unique_ptr();

    Unique_ptr(const Unique_ptr<T>& ptr) = delete;
    Unique_ptr<T>& operator=(const Unique_ptr<T>& ptr) = delete;

    Unique_ptr(Unique_ptr<T>&& ptr) noexcept;
    Unique_ptr<T>& operator=(Unique_ptr<T>&& ptr) noexcept;
    
    T& operator*() const;
    T* operator->() const;

    T* get() const;
    T* release();
    void reset(T* ptr = nullptr);
};


/*
    Implementation : unique_ptr.cpp
*/

// Constructor
template<typename T>
Unique_ptr<T>::Unique_ptr(T* ptr) 
    : data_ptr(ptr) 
{
}

// Destructor
template<typename T>
Unique_ptr<T>::~Unique_ptr() {
    delete data_ptr;
}

// Move Constructor
template<typename T>
Unique_ptr<T>::Unique_ptr(Unique_ptr<T>&& ptr) noexcept 
    : data_ptr(ptr.data_ptr) 
{
    ptr.data_ptr = nullptr;
}

// Move Assignment
template<typename T>
Unique_ptr<T>& Unique_ptr<T>::operator=(Unique_ptr<T>&& ptr) noexcept {
    if (this != &ptr) {
        delete data_ptr;
        
        data_ptr = ptr.data_ptr;
        ptr.data_ptr = nullptr;
    }
    return *this;
}

// Dereference operator
template<typename T>
T& Unique_ptr<T>::operator*() const {
    if (data_ptr == nullptr) {
        throw std::runtime_error("Attempted to dereference a null Unique_ptr");
    }
    return *data_ptr;
}

// Member Access Operator
template<typename T>
T* Unique_ptr<T>::operator->() const {
    return data_ptr;
}

// Get internal pointer method
template<typename T>
T* Unique_ptr<T>::get() const {
    return data_ptr;
}

// Release ownership method
template<typename T>
T* Unique_ptr<T>::release() {
    T* temp = data_ptr;
    data_ptr = nullptr;
    return temp;
}

// Reset method
template<typename T>
void Unique_ptr<T>::reset(T* ptr) {
    if (data_ptr != ptr) {
        delete data_ptr;
        data_ptr = ptr;
    }
}