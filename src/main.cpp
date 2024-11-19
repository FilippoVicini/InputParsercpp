#include "./input/inputOps.h"
#include "./input/parseLine.h"
#include "./models/customer.h"
#include "./models/product.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  // vector to store each line from file
  vector<string> lines;
  // map to store customer name and Customer object. No storing duplicates
  unordered_map<string, Customer *> customers;
  // input filename
  string fileName = "payments.txt";

  // File validation function
  if (!validateFile(fileName)) {
    cerr << "Invalid file: " << fileName << endl;
    return 1;
  }

  // Read File function adding each line to the vector of lines
  readFile(fileName, lines);

  // Parse Line function taking lines vector as parameter and updating the
  // customers map
  parseLine(lines, customers);

  // Return the output as per description
  cout << "Customer Map Contents:" << endl;
  for (const auto &pair : customers) {
    cout << "Customer Name: " << pair.first
         << ", Total Spent: " << pair.second->getTotalSpent() << endl;
    for (const auto &item : pair.second->getItems()) {
      cout << "  Product: " << item.name << ", Price: " << item.price << endl;
    }
  }

  return 0;
}
