#include <iostream>
using namespace std;

class NoVirtual {
private:
    int x;

public:
    void show() {
        cout << x << endl;
    }
};

class WithVirtual {
private:
    int x;

public:
    virtual void show() {
        cout << x << endl;
    }
};

class Derived : public WithVirtual {
private:
    int y;
};

int main() {
    cout << "sizeof(NoVirtual): " << sizeof(NoVirtual) << endl;
    cout << "sizeof(WithVirtual): " << sizeof(WithVirtual) << endl;
    cout << "sizeof(Derived): " << sizeof(Derived) << endl;

    const int n = 1000000;

    cout << "Memory NoVirtual: " << sizeof(NoVirtual) * n << " bytes" << endl;
    cout << "Memory WithVirtual: " << sizeof(WithVirtual) * n << " bytes" << endl;
    cout << "Memory Derived: " << sizeof(Derived) * n << " bytes" << endl;

    return 0;
}
