#include <iostream>
#include <vector>
#include "Product.h"
#include "PhysicalProduct.h"
#include "PremiumPhysical.h"
#include "DigitalProduct.h"
#include "Receipt.h"

using namespace std;

int main() {
    PhysicalProduct p1("P01", "Ban Phim Co", 400000, 1.2, 30000); 
    PremiumPhysical p2("P02", "Chuot Logitech", 300000, 0.5, 20000); 
    PremiumPhysical p3("P03", "Man hinh LG", 2500000, 4.5, 100000); 
    DigitalProduct d1("D01", "Phan mem Diet Virus", 200000, "link/download/av", 55.5); 
    
    DigitalProduct d2("D02", "Khoa hoc C++", 1000000, "link/cpp", 1500);
    d2.applyDiscount(20); 

    vector<Product*> cart = {&p1, &p2, &p3, &d1, &d2};

    Receipt receipt;
    receipt.printReceipt(cart);

    cout << "\n--- TEST FRIEND FUNCTION ---" << endl;
    compareProducts(p1, d1);
    compareProducts(p3, p1);

    return 0;
}
