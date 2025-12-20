#include <vector>
#include <stdexcept>
#include <new>
#include "../include/order_pool.h"


/**
 * @brief finds an empty pointer from free_list and allocate new order to that position in memory.
 *
 * @param args the order we need to add in book.
 *
 * @pre order must be a valid order object of the order class.
 *
 * @return the pointer where the new object is placed.
 *
 * @complexity Time complexity O(1).
 */
template<typename T>
template<typename... Args>
T* Order_Pool<T>::acquire(Args&&... args) {
    if(free_list.size() == 0) {
        throw std::runtime_error("Order Book Size Exhausted");
    }

    T* ptr = free_list.back();
    free_list.pop_back();
    new (ptr) T(std::forward<Args>(args)...);    // Creation of constructor using placement new

    return ptr;
}


/**
 * @brief free the allocated memory for the order object.
 *
 * @param obj the address of the order object in memory.
 *
 * @pre a valid order object must be allocated in the provided memory address
 *
 * @return nothing, but free_list gets updated.
 *
 * @invariant All the initial free pointers in free_list is invariant.
 *
 * @complexity Time complexity O(1).
 */
template<typename T>
void Order_Pool<T>::release(T* obj) {
    obj -> ~T();
    free_list.push_back(obj);
}



