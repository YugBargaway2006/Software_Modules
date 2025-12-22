#include <string>

class Colleague;

class Mediator {
public:
    virtual void notify(Colleague* sender, const std::string& event) = 0;
    virtual ~Mediator() = default;
};



class Colleague {
public:
    explicit Colleague(Mediator* mediator) : mediator_(mediator) {}
    virtual ~Colleague() = default;

protected:
    Mediator* mediator_;
};



#include <iostream>

class Button : public Colleague {
public:
    explicit Button(Mediator* mediator) : Colleague(mediator) {}

    void click() {
        std::cout << "Button clicked\n";
        mediator_->notify(this, "click");
    }
};

class TextBox : public Colleague {
public:
    explicit TextBox(Mediator* mediator) : Colleague(mediator) {}

    void setText(const std::string& text) {
        text_ = text;
        std::cout << "TextBox text set to: " << text_ << std::endl;
        mediator_->notify(this, "textChanged");
    }

private:
    std::string text_;
};

class Label : public Colleague {
public:
    explicit Label(Mediator* mediator) : Colleague(mediator) {}

    void update(const std::string& message) {
        std::cout << "Label updated: " << message << std::endl;
    }
};



class DialogMediator : public Mediator {
public:
    void setButton(Button* button) {
        button_ = button;
    }

    void setTextBox(TextBox* textBox) {
        textBox_ = textBox;
    }

    void setLabel(Label* label) {
        label_ = label;
    }

    void notify(Colleague* sender, const std::string& event) override {
        if (sender == button_ && event == "click") {
            label_->update("Button was clicked");
        }

        if (sender == textBox_ && event == "textChanged") {
            label_->update("Text changed in TextBox");
        }
    }

private:
    Button* button_ = nullptr;
    TextBox* textBox_ = nullptr;
    Label* label_ = nullptr;
};



int main() {
    DialogMediator mediator;

    Button button(&mediator);
    TextBox textBox(&mediator);
    Label label(&mediator);

    mediator.setButton(&button);
    mediator.setTextBox(&textBox);
    mediator.setLabel(&label);

    button.click();
    textBox.setText("Hello Mediator");

    return 0;
}
