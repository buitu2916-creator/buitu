#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double hoursWorked;
    double hourlyRate;
public:
    Employee(string n, double h, double r)
        : name(n), hoursWorked(h), hourlyRate(r) {}

    virtual double calculatePay() {
        return hoursWorked * hourlyRate;
    }

    void display() {
        cout << name << " | Pay: " << calculatePay() << endl;
    }
};

class Manager : public Employee {
private:
    double bonus;
public:
    Manager(string n, double h, double r, double b)
        : Employee(n, h, r), bonus(b) {}

    double calculatePay() override {
        return Employee::calculatePay() + bonus;  // base + bonus
    }
};

class Intern : public Employee {
public:
    Intern(string n, double h, double r)
        : Employee(n, h, r) {}

    double calculatePay() override {
        return Employee::calculatePay() * 0.8;   // trừ 20% thuế
    }
};

int main() {
    Employee e("Alice",  40, 50);
    Manager  m("Bob",    40, 50, 500);
    Intern   i("Charlie",40, 50);

    e.display();
    m.display();
    i.display();
}
