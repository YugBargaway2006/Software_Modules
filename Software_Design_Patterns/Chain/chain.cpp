#include <string>

class Handler {
public:
    virtual Handler* setNext(Handler* handler) = 0;
    virtual std::string handle(const std::string& request) = 0;
    virtual ~Handler() = default;
};



class BaseHandler : public Handler {
public:
    BaseHandler() : next_(nullptr) {}

    Handler* setNext(Handler* handler) override {
        next_ = handler;
        return handler;
    }

    std::string handle(const std::string& request) override {
        if (next_) {
            return next_->handle(request);
        }
        return "Request was not handled";
    }

protected:
    Handler* next_;
};


class ConcreteHandlerA : public BaseHandler {
public:
    std::string handle(const std::string& request) override {
        if (request == "A") {
            return "Handled by Handler A";
        }
        return BaseHandler::handle(request);
    }
};

class ConcreteHandlerB : public BaseHandler {
public:
    std::string handle(const std::string& request) override {
        if (request == "B") {
            return "Handled by Handler B";
        }
        return BaseHandler::handle(request);
    }
};

class ConcreteHandlerC : public BaseHandler {
public:
    std::string handle(const std::string& request) override {
        if (request == "C") {
            return "Handled by Handler C";
        }
        return BaseHandler::handle(request);
    }
};



#include <iostream>

int main() {
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;
    ConcreteHandlerC handlerC;

    handlerA.setNext(&handlerB)->setNext(&handlerC);

    std::cout << handlerA.handle("A") << std::endl;
    std::cout << handlerA.handle("B") << std::endl;
    std::cout << handlerA.handle("C") << std::endl;
    std::cout << handlerA.handle("D") << std::endl;

    return 0;
}
