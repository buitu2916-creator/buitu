#ifndef PHYSICAL_PRODUCT_H
#define PHYSICAL_PRODUCT_H

#include "Product.h"

class PhysicalProduct : public Product {
protected:
    double weight;
    double shippingCost;

public:
    PhysicalProduct(std::string id, std::string name, double price, double w, double ship);
    
    double getFinalPrice() const override;
    void describe() const override;
};

#endif
