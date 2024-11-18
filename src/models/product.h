#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Product {
  std::string name; // product name
  double price;     // product price

public:
  // Constructor
  Product(const std::string &name, double price);
};

#endif
