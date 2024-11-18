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

  for (const auto &line : lines) {
    istringstream line_s(line);
    if (line_s >> name >> product >> price) {
      if (customers.find(name) == customers.end()) {
        customers[name] = new Customer(name);
        cout << "Added customer: " << name << endl;
      }
      customers[name]->addItem(Product(product, price));
      cout << "Added product: " << product << " to customer: " << name << endl;
    } else {
      cerr << "Failed to parse line: " << line << endl;
    }
  }
}
