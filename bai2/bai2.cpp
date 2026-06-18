#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) : brand(b), year(y) {
        cout << "Vehicle ctor" << endl;
    }

    ~Vehicle() {
        cout << "Vehicle dtor" << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    // Gọi Vehicle constructor qua initializer list
    Car(string b, int y, int doors)
        : Vehicle(b, y), numDoors(doors) {
        cout << "Car ctor" << endl;
    }

    ~Car() {
        cout << "Car dtor" << endl;
    }

    void display() {
        cout << brand << " (" << year << ") - "
             << numDoors << " doors" << endl;
    }
};

int main() {
    Car c("Toyota", 2022, 4);
    c.display();
    return 0;
}
