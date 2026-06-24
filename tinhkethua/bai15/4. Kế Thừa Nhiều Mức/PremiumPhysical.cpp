#include "PremiumPhysical.h"
#include <iostream>

using namespace std;

PremiumPhysical::PremiumPhysical(string id, string name, double price, double w, double ship)
    : PhysicalProduct(id, name, price, w, ship) {}

double PremiumPhysical::getFinalPrice() const {
    if (getPrice() > 500000) {
        return getPrice(); // Free ship
    }
    return getPrice() + shippingCost;
}

void PremiumPhysical::describe() const {
    cout << "[Premium Vat Ly] ";
    Product::describe();
    double finalShip = (getPrice() > 500000) ? 0 : shippingCost;
    cout << " | Nang: " << weight << "kg | Ship: " << finalShip;
    if (getPrice() > 500000) cout << " (Freeship)";
    cout << endl;
}
