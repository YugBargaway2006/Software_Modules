#include <string>

class Component {
public:
    virtual std::string operation() const = 0;
    virtual ~Component() = default;
};



class ConcreteComponent : public Component {
public:
    std::string operation() const override {
        return "ConcreteComponent";
    }
};



class Decorator : public Component {
public:
    explicit Decorator(Component* component) : component_(component) {}

protected:
    Component* component_;
};



class ConcreteDecoratorA : public Decorator {
public:
    explicit ConcreteDecoratorA(Component* component)
        : Decorator(component) {}

    std::string operation() const override {
        return "DecoratorA(" + component_->operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    explicit ConcreteDecoratorB(Component* component)
        : Decorator(component) {}

    std::string operation() const override {
        return "DecoratorB(" + component_->operation() + ")";
    }
};



#include <iostream>

int main() {
    Component* component = new ConcreteComponent();

    Component* decoratorA = new ConcreteDecoratorA(component);
    Component* decoratorB = new ConcreteDecoratorB(decoratorA);

    std::cout << decoratorB->operation() << std::endl;

    delete decoratorB;
    delete decoratorA;
    delete component;

    return 0;
}
