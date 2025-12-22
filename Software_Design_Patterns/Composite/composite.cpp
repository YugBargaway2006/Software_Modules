#include <string>

class Component {
public:
    virtual void operation() const = 0;

    // Optional composite-related operations
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}

    virtual ~Component() = default;
};



#include <iostream>

class Leaf : public Component {
public:
    explicit Leaf(const std::string& name) : name_(name) {}

    void operation() const override {
        std::cout << "Leaf: " << name_ << std::endl;
    }

private:
    std::string name_;
};



#include <vector>
#include <algorithm>

class Composite : public Component {
public:
    explicit Composite(const std::string& name) : name_(name) {}

    void add(Component* component) override {
        children_.push_back(component);
    }

    void remove(Component* component) override {
        children_.erase(
            std::remove(children_.begin(), children_.end(), component),
            children_.end()
        );
    }

    void operation() const override {
        std::cout << "Composite: " << name_ << std::endl;
        for (const Component* child : children_) {
            child->operation();
        }
    }

private:
    std::string name_;
    std::vector<Component*> children_;
};



int main() {
    Component* leaf1 = new Leaf("A");
    Component* leaf2 = new Leaf("B");
    Component* leaf3 = new Leaf("C");

    Composite* root = new Composite("Root");
    Composite* branch = new Composite("Branch");

    branch->add(leaf1);
    branch->add(leaf2);
    root->add(branch);
    root->add(leaf3);

    root->operation();

    delete leaf1;
    delete leaf2;
    delete leaf3;
    delete branch;
    delete root;

    return 0;
}
