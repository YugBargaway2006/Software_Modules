/*
    Date : 18 June 2026
    Author : Yug Bargaway

    PROBLEM: Design a Custom Weak Pointer (weak_ptr)
    Design and implement a generic smart pointer that holds a non-owning ("weak") reference to an object that is managed by `Shared_ptr`. 

    Functional Requirements : 
    1. Constructor taking a `Shared_ptr`, and a destructor to manage weak references.
    2. Must fully support the Rule of Five (Copy/Move semantics).
    3. Method to check if the underlying object has been destroyed (expired).
    4. Method to safely upgrade to a `Shared_ptr` to access the data (lock).
    5. Reset method to release the current weak reference.

    Non-functional Requirements :
    1. Requires an upgraded `Control_block` shared with `Shared_ptr` that tracks both `shared_count` and `weak_count`.
    2. Thread-safe reference counting using std::atomic.
    3. Weak pointers NEVER delete the underlying data. They only delete the Control Block when both shared and weak counts reach 0.
*/

/*
    Interface / Declaration : weak_ptr.hpp
*/

#include <iostream>
#include <stdexcept>
#include <utility>
#include <atomic>

// Forward declaration of Shared_ptr
template<typename T> class Shared_ptr;

// Upgraded Control Block required for Weak_ptr support
struct Control_block {
    std::atomic<size_t> shared_count;
    std::atomic<size_t> weak_count;

    Control_block(size_t s = 1, size_t w = 0) : shared_count(s), weak_count(w) {}
};

template<typename T>
class Weak_ptr {
// Structures
private:
    T* data_ptr;
    Control_block* control;

// Behaviours
private:
    void release();

public:
    Weak_ptr();
    
    // Assumes Shared_ptr grants friend access or provides getters for its internals
    Weak_ptr(const Shared_ptr<T>& ptr);
    ~Weak_ptr();

    Weak_ptr(const Weak_ptr<T>& ptr);
    Weak_ptr<T>& operator=(Weak_ptr<T> ptr);

    Weak_ptr(Weak_ptr<T>&& ptr) noexcept;
    Weak_ptr<T>& operator=(Weak_ptr<T>&& ptr) noexcept;

    size_t count() const;
    bool expired() const;
    Shared_ptr<T> lock() const;
    void reset();
};


/*
    Implementation : weak_ptr.cpp
*/

// Helper: Safely release weak reference
template<typename T>
void Weak_ptr<T>::release() {
    if (control != nullptr) {
        if (control->weak_count.fetch_sub(1) == 1) {
            if (control->shared_count.load() == 0) {
                delete control;
            }
        }
    }
}

// Default Constructor
template<typename T>
Weak_ptr<T>::Weak_ptr() 
    : data_ptr(nullptr)
    , control(nullptr) 
{
}

// Destructor
template<typename T>
Weak_ptr<T>::~Weak_ptr() {
    release();
}

// Copy Constructor
template<typename T>
Weak_ptr<T>::Weak_ptr(const Weak_ptr<T>& ptr) 
    : data_ptr(ptr.data_ptr)
    , control(ptr.control)
{
    if (control != nullptr) {
        control->weak_count.fetch_add(1);
    }
}

// Copy Assignment
template<typename T>
Weak_ptr<T>& Weak_ptr<T>::operator=(Weak_ptr<T> ptr) {
    std::swap(data_ptr, ptr.data_ptr);
    std::swap(control, ptr.control);
    return *this;
}

// Move Constructor
template<typename T>
Weak_ptr<T>::Weak_ptr(Weak_ptr<T>&& ptr) noexcept 
    : data_ptr(ptr.data_ptr)
    , control(ptr.control) 
{
    ptr.data_ptr = nullptr;
    ptr.control = nullptr;
}

// Move Assignment
template<typename T>
Weak_ptr<T>& Weak_ptr<T>::operator=(Weak_ptr<T>&& ptr) noexcept {
    if (this != &ptr) {
        release();

        data_ptr = ptr.data_ptr;
        control = ptr.control;

        ptr.data_ptr = nullptr;
        ptr.control = nullptr;
    }
    return *this;
}

// Get shared count method
template<typename T>
size_t Weak_ptr<T>::count() const {
    return control != nullptr ? control->shared_count.load() : 0;
}

// Expired method
template<typename T>
bool Weak_ptr<T>::expired() const {
    return count() == 0;
}

// Lock method (Upgrade to Shared_ptr safely)
template<typename T>
Shared_ptr<T> Weak_ptr<T>::lock() const {
    if (expired()) {
        return Shared_ptr<T>(); 
    }
    // Assumes Shared_ptr has a constructor taking a Weak_ptr
    return Shared_ptr<T>(*this); 
}

// Reset method
template<typename T>
void Weak_ptr<T>::reset() {
    release();
    data_ptr = nullptr;
    control = nullptr;
}