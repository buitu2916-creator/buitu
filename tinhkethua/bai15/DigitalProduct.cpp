#include "DigitalProduct.h"
#include <iostream>

using namespace std;

DigitalProduct::DigitalProduct(string id, string name, double price, string url, double size)
    : Product(id, name, price), downloadUrl(url), fileSizeMB(size), discountPercent(0) {}

double DigitalProduct::applyDiscount(double percent) {
    discountPercent = percent;
    return getPrice() * (1 - percent / 100.0);
}

double DigitalProduct::getFinalPrice() const {
    if (discountPercent > 0) {
        return getPrice() * (1 - discountPercent / 100.0);
    }
    return getPrice() * 0.9;
}

void DigitalProduct::describe() const {
    cout << "[San Pham So] ";
    Product::describe();
    cout << " | Link: " << downloadUrl << " | Dung luong: " << fileSizeMB << "MB" << endl;
}
