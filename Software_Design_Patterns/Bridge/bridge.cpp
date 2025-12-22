#include <string>

class Renderer {
public:
    virtual std::string renderCircle(float radius) const = 0;
    virtual std::string renderSquare(float side) const = 0;
    virtual ~Renderer() = default;
};



class VectorRenderer : public Renderer {
public:
    std::string renderCircle(float radius) const override {
        return "Vector circle with radius " + std::to_string(radius);
    }

    std::string renderSquare(float side) const override {
        return "Vector square with side " + std::to_string(side);
    }
};

class RasterRenderer : public Renderer {
public:
    std::string renderCircle(float radius) const override {
        return "Raster circle with radius " + std::to_string(radius);
    }

    std::string renderSquare(float side) const override {
        return "Raster square with side " + std::to_string(side);
    }
};



class Shape {
public:
    explicit Shape(Renderer* renderer) : renderer_(renderer) {}
    virtual std::string draw() const = 0;
    virtual ~Shape() = default;

protected:
    Renderer* renderer_;
};



class Circle : public Shape {
public:
    Circle(Renderer* renderer, float radius)
        : Shape(renderer), radius_(radius) {}

    std::string draw() const override {
        return renderer_->renderCircle(radius_);
    }

private:
    float radius_;
};

class Square : public Shape {
public:
    Square(Renderer* renderer, float side)
        : Shape(renderer), side_(side) {}

    std::string draw() const override {
        return renderer_->renderSquare(side_);
    }

private:
    float side_;
};



#include <iostream>

int main() {
    VectorRenderer vectorRenderer;
    RasterRenderer rasterRenderer;

    Shape* c1 = new Circle(&vectorRenderer, 5.0f);
    Shape* c2 = new Circle(&rasterRenderer, 3.0f);

    Shape* s1 = new Square(&vectorRenderer, 4.0f);
    Shape* s2 = new Square(&rasterRenderer, 6.0f);

    std::cout << c1->draw() << std::endl;
    std::cout << c2->draw() << std::endl;
    std::cout << s1->draw() << std::endl;
    std::cout << s2->draw() << std::endl;

    delete c1;
    delete c2;
    delete s1;
    delete s2;

    return 0;
}
