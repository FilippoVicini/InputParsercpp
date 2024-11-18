#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "product.h"  // Ensure Product class is included here
#include <string>
#include <vector>

class Customer {
  std::string name;           // customer name
  double totalSpent;          // total cost
  std::vector<Product> items; // vector of items purchased

public:
  // Constructor (Initialize with name)
  Customer(const std::string &name);

  // Add product to the customer's list of purchased items
  void addItem(const Product &product);

  // Getter for customer name
  const std::string &getName() const;

  // Getter for the total spent
  double getTotalSpent() const;

  // Getter for the list of items
  const std::vector<Product> &getItems() const;

  // Increase the total spent (optional utility)
  void increaseTot(double cost);
};

#endif
