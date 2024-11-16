#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer {
  std::string name;          // customer name
  double totalSpent;         // total cost
  std::vector<double> items; // vector of items purchased with costs

public:
  // Constructor
  Customer(const std::string &name, double cost);

  // Add item with cost
  void addItem(double cost);

  // Getter for customer name
  const std::string &getName() const { return name; }

  // Getter for the total spent
  double getTotalSpent() const { return totalSpent; }

  // Getter for the list of items
  const std::vector<double> &getItems() const { return items; }

  // Increases the total spent (optional utility)
  void increaseTot(double cost);
};

#endif
