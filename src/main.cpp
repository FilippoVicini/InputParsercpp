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
  vector<string> lines;
  unordered_map<string, Customer *> customers;
  string fileName = "payments.txt";

  if (!validateFile(fileName)) {
    cerr << "Invalid file: " << fileName << endl;
    return 1;
  }

  readFile(fileName, lines);

  parseLine(lines, customers);

  // Print the values in the map
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
