#include <iostream>
using namespace std;

class Animal {
public:
    string name;
};

class Mammal : public Animal {
};

class WingedAnimal : public Animal {
};

class Bat : public Mammal, public WingedAnimal {
};

int main() {
    Bat b;

    // b.name = "Bat"; 
    // Loi vi Bat co 2 name: Mammal::name va WingedAnimal::name

    b.Mammal::name = "Bat from Mammal";
    b.WingedAnimal::name = "Bat from WingedAnimal";

    cout << b.Mammal::name << endl;
    cout << b.WingedAnimal::name << endl;

    return 0;
};
