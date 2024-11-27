#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
  std::string name;
  double price;

public:
  // Constructor
  Product(const std::string &name, double price);

  // Getter for name
  std::string getName() const;

  // Setter for name
  void setName(const std::string &newName);

  // Getter for price
  double getPrice() const;

  // Setter for price
  void setPrice(double newPrice);
};

#endif
