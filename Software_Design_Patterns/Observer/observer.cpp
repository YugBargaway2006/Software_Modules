#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};



#include <vector>

class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;
};



#include <algorithm>

class ConcreteSubject : public Subject {
public:
    void attach(Observer* observer) override {
        observers_.push_back(observer);
    }

    void detach(Observer* observer) override {
        observers_.erase(
            std::remove(observers_.begin(), observers_.end(), observer),
            observers_.end()
        );
    }

    void setState(const std::string& state) {
        state_ = state;
        notify();
    }

    std::string getState() const {
        return state_;
    }

    void notify() override {
        for (Observer* observer : observers_) {
            observer->update(state_);
        }
    }

private:
    std::vector<Observer*> observers_;
    std::string state_;
};



#include <iostream>

class ConcreteObserverA : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Observer A received update: " << message << std::endl;
    }
};

class ConcreteObserverB : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Observer B received update: " << message << std::endl;
    }
};



int main() {
    ConcreteSubject subject;

    ConcreteObserverA observerA;
    ConcreteObserverB observerB;

    subject.attach(&observerA);
    subject.attach(&observerB);

    subject.setState("State changed to X");
    subject.detach(&observerA);
    subject.setState("State changed to Y");

    return 0;
}
