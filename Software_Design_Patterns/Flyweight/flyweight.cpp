#include <string>

class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
    virtual ~Flyweight() = default;
};



#include <iostream>

class ConcreteFlyweight : public Flyweight {
public:
    explicit ConcreteFlyweight(const std::string& intrinsicState)
        : intrinsicState_(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "Intrinsic: " << intrinsicState_
                  << " | Extrinsic: " << extrinsicState << std::endl;
    }

private:
    std::string intrinsicState_;   // Shared state
};



#include <unordered_map>

class FlyweightFactory {
public:
    Flyweight* getFlyweight(const std::string& key) {
        auto it = flyweights_.find(key);
        if (it == flyweights_.end()) {
            flyweights_[key] = new ConcreteFlyweight(key);
        }
        return flyweights_[key];
    }

    ~FlyweightFactory() {
        for (auto& pair : flyweights_) {
            delete pair.second;
        }
    }

private:
    std::unordered_map<std::string, Flyweight*> flyweights_;
};



int main() {
    FlyweightFactory factory;

    Flyweight* fw1 = factory.getFlyweight("SharedStateA");
    Flyweight* fw2 = factory.getFlyweight("SharedStateA");
    Flyweight* fw3 = factory.getFlyweight("SharedStateB");

    fw1->operation("Context1");
    fw2->operation("Context2");
    fw3->operation("Context3");

    return 0;
}
