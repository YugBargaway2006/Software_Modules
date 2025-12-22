#include <string>

class Target {
public:
    virtual std::string request() const = 0;
    virtual ~Target() = default;
};


class Adaptee {
public:
    std::string specificRequest() const {
        return "Response from Adaptee (incompatible interface)";
    }
};



class Adapter : public Target {
public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}

    std::string request() const override {
        // Translate Target interface to Adaptee interface
        return adaptee_->specificRequest();
    }

private:
    Adaptee* adaptee_;
};



#include <iostream>

void clientCode(const Target& target) {
    std::cout << target.request() << std::endl;
}

int main() {
    Adaptee adaptee;
    Adapter adapter(&adaptee);

    clientCode(adapter);

    return 0;
}

