#include <iostream>
using namespace std;

// Khai báo trước (Forward Declaration) để Wallet biết Auditor là gì
class Auditor; 

class Wallet {
private:
    double money; // [cite: 122]
public:
    Wallet(double m) : money(m) {}

    // Khai báo friend function [cite: 123]
    friend void inspect(const Wallet& w); 

    // Khai báo friend class [cite: 124]
    friend class Auditor; 
};

// Hàm bạn (Friend Function) truy cập trực tiếp money [cite: 123]
void inspect(const Wallet& w) {
    cout << "Hàm bạn inspect(): Ví đang có " << w.money << " VND\n"; // [cite: 123]
}

// Lớp bạn (Friend Class) [cite: 124]
class Auditor {
public:
    // Phương thức audit truy cập trực tiếp money [cite: 125]
    void audit(const Wallet& w) {
        cout << "Lớp bạn Auditor::audit(): Xác minh số dư = " << w.money << " VND\n"; // [cite: 125]
    }
};

int main() {
    Wallet myWallet(500000); // Ví có 500k
    
    // Sử dụng cả hai cách để kiểm tra [cite: 126]
    inspect(myWallet); // [cite: 126]
    
    Auditor admin;
    admin.audit(myWallet); // [cite: 126]
    
    return 0;
}
