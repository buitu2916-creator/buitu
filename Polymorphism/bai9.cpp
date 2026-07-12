#include <iostream>
#include <string>
using namespace std;

// ===== Abstract class (interface chung cho mọi phương thức thanh toán) =====
class PaymentMethod {
public:
    virtual void pay(double amount) = 0;      // pure virtual - bắt buộc lớp con phải cài đặt
    virtual string getName() const = 0;       // pure virtual
    virtual ~PaymentMethod() {}               // destructor ảo - bắt buộc khi có virtual function
};

// ===== 3 lớp con ban đầu =====
class MomoPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "[Momo] Da thanh toan " << amount << " VND qua vi Momo.\n";
    }
    string getName() const override { return "Momo"; }
};

class ZaloPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "[ZaloPay] Da thanh toan " << amount << " VND qua ZaloPay.\n";
    }
    string getName() const override { return "ZaloPay"; }
};

class QRPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "[QR Code] Da quet ma QR va thanh toan " << amount << " VND.\n";
    }
    string getName() const override { return "QR Code"; }
};

// ===== Lớp mở rộng thêm (KHÔNG sửa checkout, KHÔNG sửa các lớp cũ) =====
class ShopeePayment : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "[ShopeePay] Da thanh toan " << amount << " VND qua ShopeePay.\n";
    }
    string getName() const override { return "ShopeePay"; }
};

// ===== Hàm checkout: chỉ làm việc với interface, không biết loại cụ thể =====
// Đây chính là phần "Closed for modification":
// hàm này không cần sửa dù ta thêm bao nhiêu phương thức thanh toán mới.
void checkout(PaymentMethod& method, double amount) {
    cout << "Dang xu ly thanh toan bang " << method.getName() << "...\n";
    method.pay(amount);
    cout << "-----------------------------\n";
}

int main() {
    MomoPayment momo;
    ZaloPayment zalo;
    QRPayment qr;
    ShopeePayment shopee; // lớp mới thêm vào - đây là phần "Open for extension"

    int choice;
    double amount;

    cout << "Nhap so tien can thanh toan: ";
    cin >> amount;

    cout << "Chon phuong thuc thanh toan:\n";
    cout << "1. Momo\n2. ZaloPay\n3. QR Code\n4. ShopeePay\n";
    cout << "Lua chon: ";
    cin >> choice;

    switch (choice) {
        case 1: checkout(momo, amount); break;
        case 2: checkout(zalo, amount); break;
        case 3: checkout(qr, amount); break;
        case 4: checkout(shopee, amount); break;
        default: cout << "Lua chon khong hop le!\n";
    }

    return 0;
}
