#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    void eat() {
        cout << name << " is eating..." << endl;
    }
};

class Dog : public Animal {
private:
    string breed;

public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}

    void bark() {
        cout << name << " says: Woof!" << endl;
    }

    void display() {
        cout << "Name: " << name
             << " | Age: " << age
             << " | Breed: " << breed << endl;
    }
};

int main() {
    Dog d("Buddy", 3, "Labrador");
    d.eat();      // kế thừa từ Animal
    d.bark();
    d.display();
    return 0;
}
