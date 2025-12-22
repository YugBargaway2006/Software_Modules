class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};



#include <iostream>

class Light {
public:
    void on() {
        std::cout << "Light is ON\n";
    }

    void off() {
        std::cout << "Light is OFF\n";
    }
};



class LightOnCommand : public Command {
public:
    explicit LightOnCommand(Light* light) : light_(light) {}

    void execute() override {
        light_->on();
    }

private:
    Light* light_;
};

class LightOffCommand : public Command {
public:
    explicit LightOffCommand(Light* light) : light_(light) {}

    void execute() override {
        light_->off();
    }

private:
    Light* light_;
};



class RemoteControl {
public:
    void setCommand(Command* command) {
        command_ = command;
    }

    void pressButton() {
        if (command_) {
            command_->execute();
        }
    }

private:
    Command* command_ = nullptr;
};



int main() {
    Light livingRoomLight;

    Command* lightOn = new LightOnCommand(&livingRoomLight);
    Command* lightOff = new LightOffCommand(&livingRoomLight);

    RemoteControl remote;

    remote.setCommand(lightOn);
    remote.pressButton();

    remote.setCommand(lightOff);
    remote.pressButton();

    delete lightOn;
    delete lightOff;

    return 0;
}
