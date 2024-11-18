#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
  std::string name;
  double price;

  Product(const std::string &name, double price);
};

#endif // PRODUCT_H
