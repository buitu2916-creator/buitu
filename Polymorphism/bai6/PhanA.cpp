#include <iostream>
using namespace std;

class Base {
public:
    Base() { 
        cout << "Goi constructor cua Base\n"; 
    }
    
    // Destructor KHÔNG có virtual -> Lỗi Static Binding khi delete
    ~Base() { 
        cout << "~Base\n"; 
    } 
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        cout << "Goi constructor cua Derived\n";
        data = new int[100]; // Cấp phát động
    }
    
    ~Derived() {
        cout << "~Derived\n";
        delete[] data; // Trách nhiệm dọn dẹp bộ nhớ của Derived
    }
};

int main() {
    cout << "--- PHAN A: TAI HIEN LOI ---\n";
    Base* p = new Derived(); // Upcasting
    
    cout << "\nTien hanh xoa con tro p:\n";
    delete p; 
    
    return 0;
}
