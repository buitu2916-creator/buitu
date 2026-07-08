#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "..." << endl;
    }
};

class Dog : public Animal
{
public:
    void speak() override
    {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak() override
    {
        cout << "Meow!" << endl;
    }
};

int main()
{
    Animal* ptr = new Dog();

    ptr->speak();

    delete ptr;

    return 0;
}
