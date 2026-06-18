#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNo;
    double balance;
public:
    Account(string no, double bal) : accountNo(no), balance(bal) {}

    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Không đủ số dư!\n";
    }
    double getBalance() const { return balance; }
};

class SavingsAccount : public Account {
protected:
    double interestRate; // Ví dụ: 0.05 tương đương 5%
public:
    SavingsAccount(string no, double bal, double rate) 
        : Account(no, bal), interestRate(rate) {}

    // Hàm ảo để lớp con có thể ghi đè (override)
    virtual void addInterest() {
        balance += balance * interestRate;
    }
};

class VIPSavings : public SavingsAccount {
public:
    // Nhận constructor chaining từ SavingsAccount
    VIPSavings(string no, double bal, double rate) 
        : SavingsAccount(no, bal, rate) {}

    // Ghi đè phương thức với lãi suất gấp đôi
    void addInterest() override {
        balance += balance * (interestRate * 2); 
    }
};

int main() {
    // Tạo 2 tài khoản cùng số dư gốc 100 triệu, lãi suất cơ bản 5% (0.05)
    SavingsAccount normalAcc("SAV-001", 100000000, 0.05);
    VIPSavings vipAcc("VIP-001", 100000000, 0.05);

    // Mô phỏng qua 3 kỳ tính lãi
    for (int i = 1; i <= 3; i++) {
        normalAcc.addInterest();
        vipAcc.addInterest();
    }

    cout << "Số dư tài khoản Thường sau 3 kỳ: " << normalAcc.getBalance() << " VND\n";
    cout << "Số dư tài khoản VIP sau 3 kỳ   : " << vipAcc.getBalance() << " VND\n";

    return 0;
}
