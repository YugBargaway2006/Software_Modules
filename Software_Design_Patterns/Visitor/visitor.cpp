class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA* element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB* element) = 0;
    virtual ~Visitor() = default;
};



class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
    virtual ~Element() = default;
};



#include <iostream>

class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementA(this);
    }

    void featureA() const {
        std::cout << "Feature A logic\n";
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementB(this);
    }

    void featureB() const {
        std::cout << "Feature B logic\n";
    }
};



class ConcreteVisitor : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* element) override {
        std::cout << "Visitor handling Element A\n";
        element->featureA();
    }

    void visitConcreteElementB(ConcreteElementB* element) override {
        std::cout << "Visitor handling Element B\n";
        element->featureB();
    }
};



#include <vector>

int main() {
    std::vector<Element*> elements;
    elements.push_back(new ConcreteElementA());
    elements.push_back(new ConcreteElementB());

    Visitor* visitor = new ConcreteVisitor();

    for (Element* e : elements) {
        e->accept(visitor);
    }

    delete visitor;
    for (Element* e : elements) {
        delete e;
    }

    return 0;
}
