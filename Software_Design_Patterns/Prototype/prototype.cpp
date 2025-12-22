#include <string>

class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void setData(const std::string& data) = 0;
    virtual std::string getData() const = 0;
    virtual ~Prototype() = default;
};



class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(const std::string& data) : data_(data) {}

    ConcretePrototype(const ConcretePrototype& other) {
        data_ = other.data_;
    }

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void setData(const std::string& data) override {
        data_ = data;
    }

    std::string getData() const override {
        return data_;
    }

private:
    std::string data_;
};



#include <iostream>

int main() {
    Prototype* original = new ConcretePrototype("Initial Data");

    Prototype* copy = original->clone();
    copy->setData("Modified Copy");

    std::cout << original->getData() << std::endl;
    std::cout << copy->getData() << std::endl;

    delete original;
    delete copy;

    return 0;
}
