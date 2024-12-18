#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "./product.h"
#include <string>
#include <vector>

class Customer {
  std::string name;
  double totalSpent;
  std::vector<Product> items;

public:
  // Constructor
  Customer(const std::string &name);

  // Add product to the customer's list of purchased items
  void addProduct(const Product &product);

  // Increase the total spent
  void increaseTot(double cost);

  // Getter for customer name
  const std::string &getName() const;

  // Getter for the total spent
  double getTotalSpent() const;

  // Getter for the list of items
  const std::vector<Product> &getProducts() const;
};

#endif
