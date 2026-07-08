#include <iostream>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor
    Vector2D(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }

    // Overload +
    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x + other.x, y + other.y);
    }

    // Overload -
    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x, y - other.y);
    }

    // Overload *
    Vector2D operator*(double scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    // Overload ==
    bool operator==(const Vector2D& other) {
        return x == other.x && y == other.y;
    }

    // Overload <<
    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

int main() {

    Vector2D v1(2,3);
    Vector2D v2(5,7);

    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;
    Vector2D v5 = v1 * 3;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v3 = " << v3 << endl;
    cout << "v4 = " << v4 << endl;
    cout << "v5 = " << v5 << endl;

    if(v1 == v2)
        cout << "v1 bang v2";
    else
        cout << "v1 khac v2";

    return 0;
}
