#include <iostream>
#include <string>
using namespace std;

// Tạo class Security đánh dấu final 
class Security final { 
private:
    string encryptionKey; // 
public:
    Security(string key) : encryptionKey(key) {}
    void encrypt(string data) { // 
        cout << "Đang mã hóa [" << data << "] bằng khóa: " << encryptionKey << endl;
    }
};

// Thử tạo class SuperSecurity kế thừa từ Security [cite: 114]
// class SuperSecurity : public Security {}; 
// --> Dòng trên nếu bỏ comment sẽ gây LỖI BIÊN DỊCH: "cannot inherit from 'final' class" [cite: 114]

// Tạo lớp Base với phương thức virtual final [cite: 115]
class Base {
public:
    virtual void process() final { // [cite: 115]
        cout << "Đang chạy tiến trình hệ thống (Không thể override)!\n";
    }
};

class Derived : public Base {
public:
    // Thử ghi đè (override) trong lớp con [cite: 117]
    // void process() override { cout << "Hack tiến trình.\n"; } 
    // --> Dòng trên nếu bỏ comment sẽ gây LỖI BIÊN DỊCH: "virtual function cannot be overridden"
};

int main() {
    Security secure("SECRET_KEY_123");
    secure.encrypt("ThongTinBaoMat");
    
    Derived obj;
    obj.process();
    return 0;
}
