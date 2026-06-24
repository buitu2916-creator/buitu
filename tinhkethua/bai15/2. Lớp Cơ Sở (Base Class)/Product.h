#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string id;
    std::string name;
    double price;

protected:
    double getPrice() const;
    void setPrice(double p);

public:
    Product(std::string id, std::string name, double price);
    virtual ~Product() = default;

    virtual void describe() const;
    virtual double getFinalPrice() const;

    // Khai báo Friend Function
    friend void compareProducts(const Product& p1, const Product& p2);
};

#endif
