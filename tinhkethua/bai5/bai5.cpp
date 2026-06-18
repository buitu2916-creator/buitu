#include <iostream>
using namespace std;

class BankAccount {
protected:
    double balance;
public:
    BankAccount(double b) : balance(b) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount
             << " | Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew " << amount
                 << " | Balance: " << balance << endl;
        }
    }
};

class SavingsAccount : public BankAccount {
private:
    double minimumBalance;
public:
    SavingsAccount(double b, double minBal)
        : BankAccount(b), minimumBalance(minBal) {}

    void withdraw(double amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Denied! Must keep minimum balance of "
                 << minimumBalance << endl;
        } else {
            balance -= amount;
            cout << "Withdrew " << amount
                 << " | Balance: " << balance << endl;
        }
    }
};

int main() {
    SavingsAccount sa(1000.0, 200.0);

    sa.deposit(500.0);
    sa.withdraw(1200.0);  // bị từ chối (1500 - 1200 = 300 > 200 → OK thực ra)
    sa.withdraw(1350.0);  // bị từ chối (1500 - 1350 = 150 < 200)
    sa.withdraw(1200.0);  // OK (1500 - 1200 = 300 >= 200)
}
