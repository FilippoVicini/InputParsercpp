#include "./input/inputOps.h"
#include "./input/parseLine.h"
#include "./models/customer.h"
#include "./models/product.h"
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  // vector to store each line from file
  vector<string> lines;
  // vector to store each person (preserves order)
  vector<string> people;
  // map to store customer name and Customer object. No storing duplicates
  unordered_map<string, Customer *> customers;

  string fileName = "payments.txt";
  string fileName2 = "people.txt";

  // File validation function
  if (!validateFile(fileName)) {
    cerr << "Invalid file: " << fileName << endl;
    return 1;
  } else if (!validateFile(fileName2)) {
    cerr << "Invalid file: " << fileName2 << endl;
    return 1;
  }

  // Read files into vectors
  readFile(fileName, lines);
  readFile(fileName2, people);

  // Parse the payment lines to populate the customers map
  parseLine(lines, customers);

  // Trim and store people while preserving order
  vector<string> trimmedPeople;
  for (const string &person : people) {
    size_t first = person.find_first_not_of(" \t\n\r");
    size_t last = person.find_last_not_of(" \t\n\r");
    if (first != string::npos && last != string::npos) {
      trimmedPeople.push_back(person.substr(first, last - first + 1));
    }
  }

  // Print customer information in the order they appear in people.txt
  for (const string &person : trimmedPeople) {
    auto it = customers.find(person);
    if (it != customers.end()) {
      cout << it->first << endl;

      double totalSpent = 0;
      for (const auto &product : it->second->getProducts()) {
        cout << product.getName() << " " << product.getPrice() << endl;
        totalSpent += product.getPrice();
      }

      cout << "Total: " << totalSpent << endl << endl;
    }
  }

  return 0;
}
