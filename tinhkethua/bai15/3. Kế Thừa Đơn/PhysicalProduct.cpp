#include "PhysicalProduct.h"
#include <iostream>

using namespace std;

PhysicalProduct::PhysicalProduct(string id, string name, double price, double w, double ship)
    : Product(id, name, price), weight(w), shippingCost(ship) {}

double PhysicalProduct::getFinalPrice() const {
    return getPrice() + shippingCost;
}

void PhysicalProduct::describe() const {
    cout << "[Vat Ly] ";
    Product::describe();
    cout << " | Nang: " << weight << "kg | Ship: " << shippingCost << " VND" << endl;
}
