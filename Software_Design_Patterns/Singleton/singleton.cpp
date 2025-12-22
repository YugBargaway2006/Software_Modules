#include <iostream>

class Singleton {
public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        static Singleton instance;   // Thread-safe since C++11
        return instance;
    }

    void doSomething() {
        std::cout << "Singleton instance is working\n";
    }

private:
    Singleton() {
        // Private constructor prevents direct instantiation
    }
};


int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.doSomething();

    // s1 and s2 refer to the same instance
    return 0;
}

