#include <string>

class Context;

class State {
public:
    virtual void handle(Context* context) = 0;
    virtual std::string name() const = 0;
    virtual ~State() = default;
};



#include <iostream>

class Context {
public:
    explicit Context(State* state) : state_(state) {}

    void setState(State* state) {
        state_ = state;
        std::cout << "State changed to: " << state_->name() << std::endl;
    }

    void request() {
        state_->handle(this);
    }

private:
    State* state_;
};



class ConcreteStateA : public State {
public:
    void handle(Context* context) override;
    std::string name() const override { return "State A"; }
};

class ConcreteStateB : public State {
public:
    void handle(Context* context) override;
    std::string name() const override { return "State B"; }
};



void ConcreteStateA::handle(Context* context) {
    std::cout << "Handling request in State A\n";
    static ConcreteStateB nextState;
    context->setState(&nextState);
}

void ConcreteStateB::handle(Context* context) {
    std::cout << "Handling request in State B\n";
    static ConcreteStateA nextState;
    context->setState(&nextState);
}



int main() {
    ConcreteStateA initialState;
    Context context(&initialState);

    context.request();
    context.request();
    context.request();

    return 0;
}
