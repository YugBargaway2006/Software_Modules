/*
    Date : 17 June 2026
    Author : Yug Bargaway

    PROBLEM: Design a Dynamic Hash Map (unordered_map)
    Design and implement a generic Key-Value Hash Map from scratch. The map must 
    use a dynamically allocated array of pointers and handle collisions using 
    Separate Chaining (Singly Linked Lists).

    Functional Requirements : 
    1. There should be a constructor to provide the initial bucket capacity.
    2. Methods for put, get, and remove key-value pairs.
    3. The map should automatically double in size and rehash when load factor > 0.75.
    4. Additional interfaces for size and load_factor.

    Non-functional Requirements :
    1. Dynamically Allotted Array of pointers for efficient memory management.
    2. put, get, and remove operations should be amortized O(1).
    3. Support multiple data types for Keys and Values (template programming).
    4. Follow Rule of 5 semantics (Cons / Dest, Copy, Move).
    5. Zero memory leaks during rehash or destruction.
*/


/*
    Interface / Declaration : hash_map.hpp
*/

#include <iostream>
#include <stdexcept>
#include <functional> // For std::hash
#include <utility>    // For std::swap

template<typename K, typename V>
class HashMap {
// Structures
private:
    struct HashNode {
        K key;
        V value;
        HashNode* next;
        
        HashNode(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };

    HashNode** buckets;
    size_t max_size;
    size_t map_size;
    const double max_load_factor = 0.75;

// Behaviours 
private:
    void rehash();
    void clear();

public:
    HashMap(const size_t sz = 8);
    ~HashMap();

    HashMap(const HashMap<K, V>& obj);
    HashMap& operator=(HashMap<K, V> obj);

    HashMap(HashMap<K, V>&& obj) noexcept;
    HashMap& operator=(HashMap<K, V>& obj) noexcept;

    void put(const K& key, const V& value);
    bool get(const K& key, V& out_value) const;
    bool remove(const K& key);

    size_t size() const;
    double load_factor() const;
};


/*
    Implementation : hash_map.cpp
*/

// Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap(const size_t sz) 
    : max_size(sz > 0 ? sz : 8)
    , map_size(0)
{
    buckets = new HashNode*[max_size];
    for(size_t idx = 0; idx < max_size; idx++) {
        buckets[idx] = nullptr;
    }
}

// Helper: Clear all memory
template<typename K, typename V>
void HashMap<K, V>::clear() {
    for(size_t idx = 0; idx < max_size; idx++) {
        HashNode* current = buckets[idx];
        while(current != nullptr) {
            HashNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] buckets;
}

// Destructor
template<typename K, typename V>
HashMap<K, V>::~HashMap() {
    clear();
}

// Copy Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap<K, V>& obj) {
    // Deep Copy
    max_size = obj.max_size;
    map_size = obj.map_size;

    buckets = new HashNode*[max_size];
    for(size_t idx = 0; idx < max_size; idx++) {
        buckets[idx] = nullptr;
        
        HashNode* current = obj.buckets[idx];
        HashNode* tail = nullptr;

        // Copy the linked list chain
        while(current != nullptr) {
            HashNode* new_node = new HashNode(current->key, current->value);
            if(buckets[idx] == nullptr) {
                buckets[idx] = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
            current = current->next;
        }
    }
}

// Copy Assignment
template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(HashMap<K, V> obj) {
    std::swap(buckets, obj.buckets);
    std::swap(max_size, obj.max_size);
    std::swap(map_size, obj.map_size);
    return *this;
}

// Move Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap(HashMap<K, V>&& obj) noexcept {
    // Steal pointers
    max_size = obj.max_size;
    map_size = obj.map_size;
    buckets = obj.buckets;

    obj.max_size = 0;
    obj.map_size = 0;
    obj.buckets = nullptr;
}

// Move Assignment 
template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(HashMap<K, V>& obj) noexcept {
    std::swap(buckets, obj.buckets);
    std::swap(max_size, obj.max_size);
    std::swap(map_size, obj.map_size);
    return *this;
}

// Rehash Operation
template<typename K, typename V>
void HashMap<K, V>::rehash() {
    size_t new_max_size = max_size * 2;
    HashNode** new_buckets = new HashNode*[new_max_size];
    
    for(size_t idx = 0; idx < new_max_size; idx++) {
        new_buckets[idx] = nullptr;
    }

    // Redistribute existing nodes
    for(size_t idx = 0; idx < max_size; idx++) {
        HashNode* current = buckets[idx];
        while(current != nullptr) {
            HashNode* next_node = current->next; // Save next pointer
            
            // Recalculate new bucket index
            size_t new_idx = std::hash<K>{}(current->key) % new_max_size;
            
            // Insert at the head of the new bucket
            current->next = new_buckets[new_idx];
            new_buckets[new_idx] = current;
            
            current = next_node;
        }
    }

    delete[] buckets;
    buckets = new_buckets;
    max_size = new_max_size;
}

// Put Operation
template<typename K, typename V>
void HashMap<K, V>::put(const K& key, const V& value) {
    if(load_factor() >= max_load_factor) {
        rehash();
    }

    size_t idx = std::hash<K>{}(key) % max_size;
    HashNode* current = buckets[idx];

    // Check if key already exists (Update)
    while(current != nullptr) {
        if(current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    // Key does not exist, insert at head (Collision / New Entry)
    HashNode* new_node = new HashNode(key, value);
    new_node->next = buckets[idx];
    buckets[idx] = new_node;
    map_size += 1;
}

// Get Operation
template<typename K, typename V>
bool HashMap<K, V>::get(const K& key, V& out_value) const {
    size_t idx = std::hash<K>{}(key) % max_size;
    HashNode* current = buckets[idx];

    while(current != nullptr) {
        if(current->key == key) {
            out_value = current->value;
            return true;
        }
        current = current->next;
    }

    return false;
}

// Remove Operation
template<typename K, typename V>
bool HashMap<K, V>::remove(const K& key) {
    size_t idx = std::hash<K>{}(key) % max_size;
    HashNode* current = buckets[idx];
    HashNode* prev = nullptr;

    while(current != nullptr) {
        if(current->key == key) {
            if(prev == nullptr) {
                // Node to delete is the head of the list
                buckets[idx] = current->next;
            } else {
                // Node to delete is in the middle or end
                prev->next = current->next;
            }
            delete current;
            map_size -= 1;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

// Size operation
template<typename K, typename V>
size_t HashMap<K, V>::size() const {
    return map_size;
}

// Load Factor operation
template<typename K, typename V>
double HashMap<K, V>::load_factor() const {
    return static_cast<double>(map_size) / max_size;
}