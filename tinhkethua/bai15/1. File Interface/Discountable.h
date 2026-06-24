#ifndef DISCOUNTABLE_H
#define DISCOUNTABLE_H

class Discountable {
public:
    virtual double applyDiscount(double percent) = 0;
    virtual ~Discountable() = default;
};

#endif
