#include <iostream>
using namespace std;

class Account {
private:
    double balance; // Giữ thuộc tính private 

protected:
    // Cung cấp protected getter/setter cho lớp con sử dụng 
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

// PremiumAccount kế thừa public từ Account 
class PremiumAccount : public Account {
public:
    PremiumAccount(double initialBalance) : Account(initialBalance) {}

    void addBonus() {
        // Thay vì truy cập balance trực tiếp, dùng getBalance() và setBalance() 
        double currentBalance = getBalance(); 
        setBalance(currentBalance + 100000);   // Thưởng 100k 
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
