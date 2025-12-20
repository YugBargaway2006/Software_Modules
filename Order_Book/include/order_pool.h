#pragma once

#include <vector>


template<typename T>
class Order_Pool {
private:
    size_t size = 1e5;
    std::vector<T> pool;
    std::vector<T*> free_list;

public:
    explicit Order_Pool(size_t size) 
    : size(size)
    {
        pool.resize(size);
        free_list.resize(size);

        for(int i = 0; i < size; i++) {
            pool.emplace_back();
            free_list.push_back(&pool.back());
        }
    }

    template<typename... Args>
    T* acquire(Args&&... args);
    void release(T* obj);
};