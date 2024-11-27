#include "parseLine.h"
#include "../models/customer.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
      // Error detection when line is not parsed
      cerr << "Error in line " << i + 1 << ": \"" << line
           << "\" - Expected format: <name> <product> <price> (e.g., Bob eggs "
              "2.5)"
           << endl;
    }
  }
}

/**
 * Checks if all names in the people.txt file are consistent with the map
 *
 * @param customers An unordered_map of customer names to `Customer*` objects.
 * @param people A vector of names read from people.txt.
 * @return True if all names match, false if discrepancies are found.
 */

bool fileConsistency(unordered_map<string, Customer *> customers,
                     vector<string> people) {
  bool allPresent = true;

  // Check if all people in the list are in the map
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
  unordered_set<string> peopleSet(people.begin(), people.end());
  for (const auto &entry : customers) {
    if (peopleSet.find(entry.first) == peopleSet.end()) {
      cerr << "Error: " << entry.first
           << " is present in the customers map but not listed in people.txt."
           << endl;
      allPresent = false;
    }
  }

  // Error or success message
  if (allPresent) {
    cout << "All people match between people.txt and the customers map." << endl
         << endl;
  } else {
    cout << "Discrepancies were found. See errors above." << endl;
  }

  return allPresent;
}
