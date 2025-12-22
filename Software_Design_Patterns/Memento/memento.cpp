#include <string>

class Memento {
public:
    explicit Memento(const std::string& state) : state_(state) {}

    std::string getState() const {
        return state_;
    }

private:
    std::string state_;
};



class Originator {
public:
    void setState(const std::string& state) {
        state_ = state;
    }

    std::string getState() const {
        return state_;
    }

    Memento save() const {
        return Memento(state_);
    }

    void restore(const Memento& memento) {
        state_ = memento.getState();
    }

private:
    std::string state_;
};



#include <vector>

class Caretaker {
public:
    void save(const Memento& memento) {
        history_.push_back(memento);
    }

    Memento undo() {
        Memento m = history_.back();
        history_.pop_back();
        return m;
    }

private:
    std::vector<Memento> history_;
};



#include <iostream>

int main() {
    Originator editor;
    Caretaker history;

    editor.setState("State 1");
    history.save(editor.save());

    editor.setState("State 2");
    history.save(editor.save());

    editor.setState("State 3");

    std::cout << "Current: " << editor.getState() << std::endl;

    editor.restore(history.undo());
    std::cout << "After undo: " << editor.getState() << std::endl;

    editor.restore(history.undo());
    std::cout << "After second undo: " << editor.getState() << std::endl;

    return 0;
}
