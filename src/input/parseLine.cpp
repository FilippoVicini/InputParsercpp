#include "parseLine.h"
#include "../models/customer.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Parses transaction lines and updates customer data.
 *
 * @param lines A vector of strings in the format: "<name> <product> <price>".
 * @param customers An unordered_map of customer names to `Customer*` objects.
 *
 * Adds new customers or updates existing ones with products.
 *
 */
void parseLine(const vector<string> &lines,
               unordered_map<string, Customer *> &customers) {

  string name, product;
  double price;

  // Loop through the lines vector
  for (size_t i = 0; i < lines.size(); ++i) {
    const auto &line = lines[i];
    istringstream line_s(line);

    // Parse the line for expected format: name product price
    if (line_s >> name >> product >> price) {

      // if customer is not found in the map
      if (customers.find(name) == customers.end()) {
        customers[name] = new Customer(name);
      }
      // Customer is found, update the customer's products
      customers[name]->addProduct(Product(product, price));

    } else {
      cerr << "Error in payments.txt, line " << i + 1 << ": \"" << line
           << "\" - Expected format: <name> <product> <price> (e.g., Bob eggs "
              "2.5)"
           << endl;
      exit(1);
    }
  }
}
