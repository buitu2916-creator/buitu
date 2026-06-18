#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
public:
    Shape(string c) : color(c) {}

    void describe() {
        cout << "Shape: " << color << endl;
    }

    double area() { return 0.0; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string c, double r) : Shape(c), radius(r) {}

    void describe() {
        Shape::describe();   // gọi lại logic cha
        cout << "Circle | radius = " << radius << endl;
    }

    double area() { return M_PI * radius * radius; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(string c, double w, double h)
        : Shape(c), width(w), height(h) {}

    void describe() {
        Shape::describe();   // gọi lại logic cha
        cout << "Rectangle | " << width << " x " << height << endl;
    }

    double area() { return width * height; }
};

int main() {
    Circle    c("red", 5.0);
    Rectangle r("blue", 4.0, 6.0);

    c.describe();
    cout << "Area = " << c.area() << endl;

    cout << endl;

    r.describe();
    cout << "Area = " << r.area() << endl;
}
