#ifndef PREMIUM_PHYSICAL_H
#define PREMIUM_PHYSICAL_H

#include "PhysicalProduct.h"

class PremiumPhysical : public PhysicalProduct {
public:
    PremiumPhysical(std::string id, std::string name, double price, double w, double ship);
    
    double getFinalPrice() const override;
    void describe() const override;
};

#endif
