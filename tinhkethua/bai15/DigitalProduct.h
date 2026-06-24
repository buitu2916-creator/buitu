#ifndef DIGITAL_PRODUCT_H
#define DIGITAL_PRODUCT_H

#include "Product.h"
#include "Discountable.h"
#include <string>

class DigitalProduct : public Product, public Discountable {
private:
    std::string downloadUrl;
    double fileSizeMB;
    double discountPercent;

public:
    DigitalProduct(std::string id, std::string name, double price, std::string url, double size);

    double applyDiscount(double percent) override;
    double getFinalPrice() const override;
    void describe() const override;
};

#endif
