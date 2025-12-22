class Strategy {
public:
    virtual int execute(int a, int b) const = 0;
    virtual ~Strategy() = default;
};



class AddStrategy : public Strategy {
public:
    int execute(int a, int b) const override {
        return a + b;
    }
};

class SubtractStrategy : public Strategy {
public:
    int execute(int a, int b) const override {
        return a - b;
    }
};

class MultiplyStrategy : public Strategy {
public:
    int execute(int a, int b) const override {
        return a * b;
    }
};



class Context {
public:
    explicit Context(Strategy* strategy) : strategy_(strategy) {}

    void setStrategy(Strategy* strategy) {
        strategy_ = strategy;
    }

    int executeStrategy(int a, int b) const {
        return strategy_->execute(a, b);
    }

private:
    Strategy* strategy_;
};



#include <iostream>

int main() {
    AddStrategy add;
    SubtractStrategy subtract;
    MultiplyStrategy multiply;

    Context context(&add);
    std::cout << context.executeStrategy(5, 3) << std::endl;

    context.setStrategy(&subtract);
    std::cout << context.executeStrategy(5, 3) << std::endl;

    context.setStrategy(&multiply);
    std::cout << context.executeStrategy(5, 3) << std::endl;

    return 0;
}
