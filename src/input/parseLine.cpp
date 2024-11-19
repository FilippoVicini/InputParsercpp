#include "parseLine.h"
#include "../models/customer.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void parseLine(const vector<string> &lines,
               unordered_map<string, Customer *> &customers) {

  string name, product;
  double price;

  // Loop through the lines vector
  for (const auto &line : lines) {
    // Parse each line
    istringstream line_s(line);
    // Split at the space and take name, product, price
    if (line_s >> name >> product >> price) {
      // if name == end means that its not found in the map
      if (customers.find(name) == customers.end()) {
        // add a new customer to the map
        customers[name] = new Customer(name);
        cout << "Added customer: " << name << endl;
      }
      // if not means it was already in the map so update the product of the
      // customer
      customers[name]->addItem(Product(product, price));
      cout << "Added product: " << product << " to customer: " << name << endl;
    } else {
      // error detection
      cerr << "Failed to parse line: " << line << endl;
    }
  }
}
