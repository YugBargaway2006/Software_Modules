/*
    Date : 16 June 2026
    Author : Yug Bargaway

    PROBLEM: Design a Fixed-Size Circular Queue (Ring Buffer)
    Design and implement a generic queue data structure using a fixed-size raw array. The queue must support First-In-First-Out (FIFO) operations and 
    efficiently reuse memory by wrapping indices around the end of the array.

    Requirements : 
    1. It should support FIFO operations for all data types
    2. Constructor to set maximum size of ring buffer
    3. Operations of enqueue and dequeue available in O(1)
    4. Interface to check if queue is empty of not. Additional to check full or not in O(1)
    5. Interface to view the top of the queue as well as size in O(1)
    6. Use of dynamically allotted array data structure for efficient memory handling
    7. Optionally support copy and move semantics.
*/


/*
    Interface : queue.hpp
*/

#include <iostream>
#include <stdexcept>

template<typename T>
class Queue {
// Structures of the Queue
private:
    T* container;
    int max_size;
    int queue_size;
    int front;
    int back;

// Behaviours
public:
    Queue(const int sz);    // Default Constructor
    ~Queue();    // Destructor
    Queue(const Queue& obj);    // Copy Constructor (Additionally we can support copy assignment)
    Queue(Queue&& obj) noexcept;   // Move Constructor (Additionally we can support move assignment)

    void enqueue(const T& obj);    // Add to back
    void dequeue();    // Remove from front
    bool is_full() const;
    bool is_empty() const;
    int size() const;
    T& front() const;
};


/*
    Implementation : queue.cpp
*/

// Constructor
template<typename T>
Queue<T>::Queue(const int sz) 
    : max_size(sz)
    , queue_size(0)
    , front(0)
    , back(0)
{
    container = new T[max_size];
}

// Destructor
template<typename T>
Queue<T>::~Queue() {
    delete[] container;
}

// Copy Constructor
template<typename T>
Queue<T>::Queue(const Queue<T>& obj) {
    // Proceeding with a deep copy
    max_size = obj.max_size;
    queue_size = obj.queue_size;
    front = obj.front;
    back = obj.back;

    container = new T[max_size];
    for(size_t i = 0; i < max_size; i++) {
        container[i] = obj.container[i];
    }
}

// Move Constructor
template<typename T>
Queue<T>::Queue(Queue<T>&& obj) noexcept {
    max_size = obj.max_size;
    queue_size = obj.queue_size;
    front = obj.front;
    back = obj.back;
    container = obj.container;

    obj.container = nullptr;
    obj.back = 0;
    obj.front = 0;
    obj.queue_size = 0;
    obj.max_size = 0;
}

// Enqueue
template<typename T>
void Queue<T>::enqueue(const T& obj) {
    if(queue_size == max_size) {
        throw std::runtime_error("Queue is fulled. No space in Queue!")
    }
    
    container[back] = obj;
    back = (back + 1) % max_size;
    queue_size += 1;
}

// Dequeue
template<typename T>
void Queue<T>::dequeue() {
    if(queue_size == 0) {
        throw std::runtime_error("Queue is Empty. No Item available in Queue!");
    }
    
    front = (front + 1) % max_size;
    queue_size -= 1;
}

// Check if full
template<typename T>
bool Queue<T>::is_full() const {
    return (queue_size == max_size) ? true : false;
}

// Check if empty
template<typename T>
bool Queue<T>::is_empty() const {
    return (queue_size == 0) ? true : false;
}

// Size of Queue
template<typename T>
int Queue<T>::size() const {
    return queue_size;
}

// Front of Queue
template<typename T>
T& Queue<T>::front() const {
    return container[front];
}