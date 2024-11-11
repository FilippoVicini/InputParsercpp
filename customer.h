#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class customer {
  std::string n;             // customer name
  double cost;               // total cost
  std::vector<double> items; // vector of items purchased as costs

public:
  customer(const std::string &name, double c); // constructor
  void addItem(double i);                      // add item with cost
  void increaseTot(double i);
};

#endif
