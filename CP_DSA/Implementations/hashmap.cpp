/*
    Date : 17 June 2026
    Author : Yug Bargaway

    PROBLEM: Design a Dynamic Hash Map (unordered_map)
    Design and implement a generic Key-Value Hash Map from scratch. The map must use a dynamically allocated
    array of pointers and handle collisions using Separate Chaining (Singly Linked Lists).

    Functional Requirements : 
    1. There should be a constructor with initial size parameter
    2. There should be a put method and a get method, with bool as return.
    3. It should also support removal of keys
    4. There should be methods to know load factor as well as number of key value pairs stored.

    Non-Functional Requirements :
    1. Hashmap should be dynamically allotted for efficient memory management.
    2. The method should be amortized O(1)
    3. Following C++ idiom of Getter and Setter to properly encapsulate and safeguard inner state of map
    4. Optionally, we will support the Rule of 5 for the C++ class
*/

/*
    Interface / Declaration : Hashmap.hpp
*/

#include <iostream>
#include <stdexcept>
#include <utility>

template<typename K, typename V>
class Node {
// Structures
private:
    K key;
    V value;
    Node* next_node;

// Behaviours
public:
    Node(const K& key, const V& value, Node<K, V>* next_node = nullptr);
    ~Node();

    Node(const Node& obj);
    Node& operator=(const Node obj);

    Node(Node&& obj) noexcept;
    Node& operator=(Node&& obj) noexcept;

    void update(const V& value, const Node* obj) const;
    const Node* next() const;
    const std::pair<K, V> get() const;
};


template<typename K, typename V>
class Hashmap {
// Stuctures
private:
    size_t size;
    size_t buckets;
    Node** container;

// Behaviours
private:
    size_t bucket_idx(const K& key);
    void increase_size();
    const double load_factor() const;

public:
    Hashmap(const size_t size);
    ~Hashmap();

    Hashmap(const Hashmap& obj);
    Hashmap& operator=(const Hashmap obj);

    Hashmap(Node&& obj) noexcept;
    Hashmap& operator=(Node&& obj) noexcept;

    void put(const K& key, const V& value);
    bool get(const K& key, V& out_value);
    bool remove(const K& key);
    const size_t size() const;
};


/*
    Implementation : hashmap.cpp
*/

// Node Constructor
template<typename K, typename V>
Node<K, V>::Node(const K& key, const V& value, Node<K, V>* next_node = nullptr) 
    : key(key)
    , value(value)
    , next_node(next_node)
{}
    
// Node Destructor
template<typename K, typename V>
Node<K, V>::~Node() {
    delete next_node;
}

// Update Value
template<typename K, typename V>
void Node<K, V>::update(const V& value, const Node* obj) const {
    this->value = value;
    this->next_node = obj;
}

// Get next node
template<typename K, typename V>
const Node<K, V>* Node<K, V>::next() const {
    return next_node;
}

// Get key value pair
template<typename K, typename V>
const std::pair<K, V> Node<K, V>::get() const {
    return static_cast<pair<K, V>>({key, value});
}


// Hashmap Constructor
template<typename K, typename V>
Hashmap<K, V>::Hashmap(const size_t size) 
    : buckets(size)
    , size(0)
{
    container = new Node*[buckets];
}

// Hashmap Destructor
template<typename K, typename V>
Hashmap<K, V>::~Hashmap() {
    for(size_t idx = 0; idx < buckets; idx++) {
        delete container[idx];
    }

    delete[] container;
}

// Bucket Idx for Key
template<typename K, typename V>
size_t Hashmap<K, V>::bucket_idx(const K& key) {
    long long hash_value = std::hash<K>{}(key);
    size_t idx = hash_value % buckets;
    return idx;
}

// Increase Size of Map
template<typename K, typename V>
void Hashmap<K, V>::increase_size() {
    size_t new_buckets = 2 * buckets;
    Node** new_container = new Node*[new_buckets];

    buckets = new_buckets;

    for(size_t idx = 0; idx < buckets / 2; idx++) {
        std::pair<K, V> data = container[idx]->get();
        size_t new_idx = bucket_idx(data.first);
        new_container[new_idx] = move(container[idx]);
    }

    delete[] container;

    container = new_container;
}

// Calculate load factor
template<typename K, typename V>
const double Hashmap<K, V>::load_factor() const {
    return static_cast<double>(size) / buckets;
}

template<typename K, typename V>
void Hashmap<K, V>::put(const K& key, const V& value) {
    if(load_factor() > 0.75) {
        increase_size();
    }

    size_t idx = bucket_idx(key);

    Node* curr_node = container[idx];
    if(curr_node == nullptr) {
        Node* node = new Node(key, value, nullptr);
        container[idx] = node;
    } 
    else {
        while(curr_node -> next() != nullptr) {
            curr_node = curr_node -> next();
        }
        Node* node = new Node(key, value, nullptr);
        curr_node -> update(value, node)
    }



}



bool get(const K& key, V& out_value);
bool remove(const K& key);
const size_t size() const;