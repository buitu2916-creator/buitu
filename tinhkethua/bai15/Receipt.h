#ifndef RECEIPT_H
#define RECEIPT_H

#include "Product.h"
#include <vector>

class Receipt final {
public:
    void printReceipt(const std::vector<Product*>& cart) const;
};

#endif
