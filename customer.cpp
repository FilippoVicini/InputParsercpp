#include "customer.h"

// Constructor implementation
customer::customer(const std::string &name, double c) : n(name), cost(c) {}

// addItem implementation
void customer::addItem(double i) { items.push_back(i); }

void customer::increaseTot(double i) { cost = cost + i; }
