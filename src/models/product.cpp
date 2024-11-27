#include "Product.h"

// Constructor
Product::Product(const std::string &name, double price) : name(name), price(price) {}

// Getter for name
std::string Product::getName() const {
  return name;
}

// Setter for name
void Product::setName(const std::string &newName) {
  name = newName;
}

// Getter for price
double Product::getPrice() const {
  return price;
}

// Setter for price
void Product::setPrice(double newPrice) {
  price = newPrice;
}
