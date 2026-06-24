#include <iostream>
#include <string>
using namespace std;

// Lớp cha cao nhất
class Animal {
public:
    string name;
    
    // Constructor của Animal
    Animal(string n) : name(n) {
        cout << "[Animal] Constructor duoc goi." << endl;
    }
};

// Lớp trung gian 1: Kế thừa ảo (virtual inheritance) từ Animal
class Mammal : virtual public Animal {
public:
    Mammal(string n) : Animal(n) {
        cout << "[Mammal] Constructor duoc goi." << endl;
    }
};

// Lớp trung gian 2: Kế thừa ảo (virtual inheritance) từ Animal
class WingedAnimal : virtual public Animal {
public:
    WingedAnimal(string n) : Animal(n) {
        cout << "[WingedAnimal] Constructor duoc goi." << endl;
    }
};

// Lớp con cuối cùng: Kế thừa đa lớp từ Mammal và WingedAnimal
class Bat : public Mammal, public WingedAnimal {
public:
    // LƯU Ý: Phải gọi trực tiếp constructor của Animal từ đây
    Bat(string n) : Animal(n), Mammal(n), WingedAnimal(n) {
        cout << "[Bat] Constructor duoc goi." << endl;
    }

    void display() {
        // Nhờ có chữ "virtual" ở trên, biến 'name' giờ chỉ có 1 bản sao duy nhất.
        // Trình biên dịch không còn bị lỗi "ambiguous" (mơ hồ) nữa.
        cout << "Ten cua sinh vat la: " << name << endl;
    }
};

int main() {
    cout << "--- Khoi tao doi tuong Bat ---" << endl;
    Bat myBat("Doi Batman");
    
    cout << "\n--- Truy cap thuoc tinh ---" << endl;
    myBat.display();

    return 0;
}
