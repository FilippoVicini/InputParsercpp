#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    std::string name;  // Product name
    double price;      // Product price

    // Constructor for initializing Product object (declaration)
    Product(const std::string &name, double price);
};

#endif
