#include "customer.h"

// Constructor implementation
Customer::Customer(const std::string &name) : name(name), totalSpent(0) {}

// Add product to the customer's list of items
void Customer::addProduct(const Product &product) {
  items.push_back(product);         // Add the product to the list
  totalSpent += product.getPrice(); // Add the product price to the total spent
}

// Increase the total spent by a certain amount
void Customer::increaseTot(double cost) {
  totalSpent += cost; // Increase the total amount spent by the specified cost
}

// Getter for customer name
const std::string &Customer::getName() const { return name; }

// Getter for the total spent
double Customer::getTotalSpent() const { return totalSpent; }

// Getter for the list of items
const std::vector<Product> &Customer::getProducts() const { return items; }
