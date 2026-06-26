#include <iostream>
using namespace std;

class Animal {
public:
    string name;

    Animal(string n = "") {
        name = n;
        cout << "Animal constructor" << endl;
    }
};

class Mammal : virtual public Animal {
public:
    Mammal() {
        cout << "Mammal constructor" << endl;
    }
};

class WingedAnimal : virtual public Animal {
public:
    WingedAnimal() {
        cout << "WingedAnimal constructor" << endl;
    }
};

class Bat : public Mammal, public WingedAnimal {
public:
    Bat(string n) : Animal(n) {
        cout << "Bat constructor" << endl;
    }
};

int main() {
    Bat b("Bat");

    cout << b.name << endl;

    return 0;
}
