#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const {
        return 0;
    }

    virtual void draw() const {
        cout << "Drawing shape" << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double r;

public:
    Circle(double r) {
        this->r = r;
    }

    double area() const override {
        return 3.14 * r * r;
    }

    void draw() const final {
        cout << "Drawing circle" << endl;
    }
};

class SpecialCircle : public Circle {
public:
    SpecialCircle(double r) : Circle(r) {}

    double area() const override {
        return Circle::area() * 2;
    }

    /*
    void draw() const override {
        cout << "Drawing special circle" << endl;
    }
    */
};

int main() {
    SpecialCircle c(5);

    cout << c.area() << endl;
    c.draw();

    return 0;
}
