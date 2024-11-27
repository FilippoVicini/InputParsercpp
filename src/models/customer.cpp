#include "customer.h"

/**
 * Constructor
 *
 * Constructs a Customer object with a given name and initializes total
 * spent to 0.
 *
 * @param name The name of the customer.
 */
Customer::Customer(const std::string &name) : name(name), totalSpent(0) {}

/**
 * Add product to the customer's list of items
 *
 * @param product The product to be added to the customer's list.
 */
void Customer::addProduct(const Product &product) {
  items.push_back(product);
  totalSpent += product.getPrice();
}

/**
 * Increase the total spent by a certain amount
 *
 * @param cost The amount to add to the total spent.
 */
void Customer::increaseTot(double cost) { totalSpent += cost; }

// Getter for customer name
const std::string &Customer::getName() const { return name; }

// Getter for the total spent
double Customer::getTotalSpent() const { return totalSpent; }

// Getter for the list of items
const std::vector<Product> &Customer::getProducts() const { return items; }
