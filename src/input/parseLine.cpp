#include "parseLine.h"
#include "../models/customer.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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
      if (customers.find(name) == customers.end()) {
        // Add a new customer to the map
        customers[name] = new Customer(name);
        // cout << "Added customer: " << name << endl;
      }
      // Update the customer's products
      customers[name]->addItem(Product(product, price));
      // cout << "Added product: " << product << " to customer: " << name <<
      // endl;
    } else {
      // Error detection with details
      cerr << "Error in line " << i + 1 << ": \"" << line
           << "\" - Expected format: <name> <product> <price> (e.g., Bob eggs "
              "2.5)"
           << endl;
    }
  }
}

bool fileConsistency(unordered_map<string, Customer *> customers,
                     vector<string> people) {
  // Track errors
  bool allPresent = true;

  // Check if all people in the list are in the map
  // cout << "Checking people listed in people.txt..." << endl;
  for (const auto &person : people) {
    if (customers.find(person) == customers.end()) {
      cerr
          << "Error: " << person
          << " is listed in people.txt but is not present in the customers map."
          << endl;
      allPresent = false;
    }
  }

  // Check if all customers in the map are in the people list
  // cout << "Checking extra people in the customers map..." << endl;
  unordered_set<string> peopleSet(
      people.begin(), people.end()); // Convert to set for fast lookups
  for (const auto &entry : customers) {
    if (peopleSet.find(entry.first) == peopleSet.end()) {
      cerr << "Error: " << entry.first
           << " is present in the customers map but not listed in people.txt."
           << endl;
      allPresent = false;
    }
  }

  if (allPresent) {
    cout << "All people match between people.txt and the customers map."
         << endl;
  } else {
    cout << "Discrepancies were found. See errors above." << endl;
  }

  return allPresent;
}
