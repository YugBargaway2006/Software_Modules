#include <iostream>
#include <string>

class SubsystemA {
public:
    std::string operationA() const {
        return "SubsystemA: Ready\n";
    }
};

class SubsystemB {
public:
    std::string operationB() const {
        return "SubsystemB: Processing\n";
    }
};

class SubsystemC {
public:
    std::string operationC() const {
        return "SubsystemC: Completed\n";
    }
};



class Facade {
public:
    Facade()
        : subsystemA_(new SubsystemA()),
          subsystemB_(new SubsystemB()),
          subsystemC_(new SubsystemC()) {}

    ~Facade() {
        delete subsystemA_;
        delete subsystemB_;
        delete subsystemC_;
    }

    std::string operation() const {
        std::string result;
        result += subsystemA_->operationA();
        result += subsystemB_->operationB();
        result += subsystemC_->operationC();
        return result;
    }

private:
    SubsystemA* subsystemA_;
    SubsystemB* subsystemB_;
    SubsystemC* subsystemC_;
};



int main() {
    Facade facade;
    std::cout << facade.operation();
    return 0;
}
