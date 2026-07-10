#include <iostream>
using namespace std;

class Base {
public:
    Base() { 
        cout << "Goi constructor cua Base\n"; 
    }
    
    // Đã thêm từ khóa virtual
    virtual ~Base() { 
        cout << "~Base\n"; 
    } 
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        cout << "Goi constructor cua Derived\n";
        data = new int[100];
    }
    
    // Tốt nhất nên thêm từ khóa override để code rõ ràng hơn
    ~Derived() override { 
        cout << "~Derived\n";
        delete[] data; 
    }
};

int main() {
    cout << "--- PHAN B: DA SUA LOI ---\n";
    Base* p = new Derived();
    
    cout << "\nTien hanh xoa con tro p:\n";
    delete p; 
    
    return 0;
}
