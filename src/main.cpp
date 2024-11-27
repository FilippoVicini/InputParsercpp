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
  // vector to store each people
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

  // Read File function adding each line to the vector of lines
  readFile(fileName, lines);
  readFile(fileName2, people);

  // Parse Line function taking lines vector as parameter and updating the
  // customer map
  parseLine(lines, customers);

  if (fileConsistency(customers, people)) {
    // Iterate over the map and print the required output
    for (const auto &pair : customers) {
      // Print customer name
      cout << pair.first << endl;

      // Access and print items and prices
      double totalSpent = 0;
      for (const auto &product : pair.second->getProducts()) {
        cout << product.getName() << " " << product.getPrice() << endl;
        totalSpent += product.getPrice();
      }

      // Print total spent
      cout << "Total: " << totalSpent << endl << endl;
    }
  }

  return 0;
}
