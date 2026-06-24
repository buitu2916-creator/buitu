#include "Receipt.h"
#include <iostream>

using namespace std;

void Receipt::printReceipt(const vector<Product*>& cart) const {
    double total = 0;
    cout << "\n================= BIEN LAI THANH TOAN =================\n";
    for (const auto& product : cart) {
        product->describe();
        double finalP = product->getFinalPrice();
        cout << "   -> Thanh tien: " << finalP << " VND\n\n";
        total += finalP;
    }
    cout << "-------------------------------------------------------\n";
    cout << "TONG CONG THANH TOAN: " << total << " VND\n";
    cout << "=======================================================\n";
}
