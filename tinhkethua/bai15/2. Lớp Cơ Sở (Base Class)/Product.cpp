#include "Product.h"
#include <iostream>

using namespace std;

double Product::getPrice() const { return price; }

void Product::setPrice(double p) { 
    if (p >= 0) price = p; 
}

Product::Product(string id, string name, double price) : id(id), name(name) {
    setPrice(price);
}

void Product::describe() const {
    cout << "ID: " << id << " | Ten: " << name << " | Gia goc: " << price << " VND";
}

double Product::getFinalPrice() const {
    return getPrice();
}

// Định nghĩa Friend Function
void compareProducts(const Product& p1, const Product& p2) {
    cout << "So sanh: " << p1.name << " (" << p1.price << " VND) va " 
         << p2.name << " (" << p2.price << " VND) -> ";
    if (p1.price > p2.price) cout << p1.name << " dat hon.\n";
    else if (p1.price < p2.price) cout << p2.name << " dat hon.\n";
    else cout << "Hai san pham bang gia nhau.\n";
}
