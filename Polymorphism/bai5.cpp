#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal says: ..." << endl;
    }

    virtual ~Animal() {
    }
};

class Dog : public Animal {
private:
    string breed;

public:
    Dog(string breed) {
        this->breed = breed;
    }

    void speak() override {
        cout << "Dog says: Woof! Breed: " << breed << endl;
    }
};

void byValue(Animal a) {
    cout << "byValue: ";
    a.speak();
}

void byPointer(Animal* a) {
    cout << "byPointer: ";
    a->speak();
}

void byReference(Animal& a) {
    cout << "byReference: ";
    a.speak();
}

int main() {
    Dog dog("Husky");

    byValue(dog);
    byPointer(&dog);
    byReference(dog);

    return 0;
}
