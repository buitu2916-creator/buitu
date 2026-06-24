#include <iostream>
using namespace std;

class Account {
private:
    double balance; // Giữ data private

protected:
    // Cung cấp protected getter cho lớp con
    double getBalance() const {
        return balance;
    }

    // Cung cấp protected setter cho lớp con, có kèm validation
    void setBalance(double newBalance) {
        if (newBalance >= 0) {
            balance = newBalance;
        } else {
            cout << "[Lỗi] Số dư không thể âm!" << endl;
        }
    }

public:
    // Constructor
    Account(double initialBalance = 0.0) {
        balance = 0;
        setBalance(initialBalance); // Sử dụng setter ngay trong constructor
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Đã nạp: $" << amount << endl;
        }
    }

    void displayBalance() const {
        cout << "Số dư hiện tại: $" << balance << endl;
    }
};

class PremiumAccount : public Account {
public:
    PremiumAccount(double initialBalance) : Account(initialBalance) {}

    // Phương thức riêng của lớp con
    void addBonus(double bonusAmount) {
        if (bonusAmount > 0) {
            // Sử dụng getter và setter protected thay vì truy cập trực tiếp biến balance
            double currentBalance = getBalance(); 
            setBalance(currentBalance + bonusAmount);
            cout << "Đã cộng điểm thưởng: $" << bonusAmount << endl;
        }
    }
    
    // Thử tạo một phương thức giả lập lỗi để kiểm tra validation
    void forceNegativeBalance() {
        cout << "Thử ép số dư về âm..." << endl;
        setBalance(-500); // Sẽ bị chặn bởi logic validation trong setBalance()
    }
};

int main() {
    cout << "--- Khởi tạo tài khoản Premium ---" << endl;
    PremiumAccount myAcc(1000);
    myAcc.displayBalance();

    cout << "\n--- Thêm bonus ---" << endl;
    myAcc.addBonus(200);
    myAcc.displayBalance();
    
    cout << "\n--- Cố tình gán số dư âm từ lớp con ---" << endl;
    myAcc.forceNegativeBalance();
    myAcc.displayBalance();

    return 0;
}
