#include <string>

class Subject {
public:
    virtual std::string request() const = 0;
    virtual ~Subject() = default;
};



class RealSubject : public Subject {
public:
    std::string request() const override {
        return "RealSubject: Handling request";
    }
};



#include <iostream>

class Proxy : public Subject {
public:
    explicit Proxy(Subject* realSubject)
        : realSubject_(realSubject) {}

    std::string request() const override {
        if (checkAccess()) {
            std::string result = realSubject_->request();
            logAccess();
            return result;
        }
        return "Proxy: Access denied";
    }

private:
    bool checkAccess() const {
        // Access control logic
        return true;
    }

    void logAccess() const {
        std::cout << "Proxy: Logging access\n";
    }

    Subject* realSubject_;
};



#include <iostream>

int main() {
    Subject* realSubject = new RealSubject();
    Subject* proxy = new Proxy(realSubject);

    std::cout << proxy->request() << std::endl;

    delete proxy;
    delete realSubject;

    return 0;
}
