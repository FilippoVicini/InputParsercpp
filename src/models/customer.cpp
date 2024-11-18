#include "customer.h"

// Constructor implementation
Customer::Customer(const std::string &name, double cost)
    : name(name), totalSpent(cost) {
  // initial item cost
  items.push_back(cost);
}

// addItem implementation
void Customer::addItem(double cost) {
  items.push_back(cost);
  totalSpent += cost;
}

// increaseTot
void Customer::increaseTot(double cost) {
  // Increasetotal
  totalSpent += cost;
}
