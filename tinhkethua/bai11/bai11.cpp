#include <iostream>
using namespace std;

class Account {
private:
    double balance; // Giữ thuộc tính private [cite: 134]

protected:
    // Cung cấp protected getter/setter cho lớp con sử dụng [cite: 131, 135]
    double getBalance() const { // 
        return balance; 
    }
    
    void setBalance(double amount) { // Có validation 
        if (amount >= 0) {
            balance = amount;
        } else {
            cout << "Lỗi: Số tiền không hợp lệ (Không được âm)!\n";
        }
    }

public:
    Account(double initialBalance) {
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }
    
    void deposit(double amount) { // 
        if (amount > 0) balance += amount;
    }
    
    void displayBalance() const { // 
        cout << "Số dư tài khoản: " << balance << " VND\n";
    }
};

// PremiumAccount kế thừa public từ Account [cite: 136]
class PremiumAccount : public Account {
public:
    PremiumAccount(double initialBalance) : Account(initialBalance) {}

    void addBonus() {
        // Thay vì truy cập balance trực tiếp, dùng getBalance() và setBalance() [cite: 136]
        double currentBalance = getBalance(); // [cite: 136]
        setBalance(currentBalance + 100000);   // Thưởng 100k [cite: 136]
    }
};

int main() {
    PremiumAccount pAcc(500000);
    pAcc.displayBalance();
    
    cout << "--- Nhận thưởng Premium ---\n";
    pAcc.addBonus();
    pAcc.displayBalance();
    
    return 0;
}
