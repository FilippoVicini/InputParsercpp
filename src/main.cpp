#include "./input/inputOps.h"
#include "./models/customer.h"
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

void parseLine(vector<string> lines,
               unordered_map<string, Customer *> &customers) {
  string name, product;
  double price;

  for (int i = 0; i < lines.size(); i++) {
    istringstream line_s(lines[i]);
    string name;
    string product;
    double x;
    if (line_s >> name >> product >> x) {
      customers.insert(make_pair(name, new Customer(name))); // Use 'name' as the key
      cout << "Added: " << name << endl;
    }
  }
}

int main() {
  vector<string> lines = {"Alice Widget 19.99", "Bob Gadget 25.49"};
  unordered_map<string, Customer *> customers;
  string fileName = "payments.txt";

  validateFile(fileName);

  readFile(fileName, lines);

  parseLine(lines, customers);

  // Print the values in the map
  cout << "Customer Map Contents:" << endl;
  for (const auto& pair : customers) {
    cout << "Customer Name: " << pair.first << ", Customer Object: " << pair.second->getName() << endl;
  }

  // Optional: Clean up dynamically allocated memory (important to avoid memory leaks)
  for (auto& pair : customers) {
    delete pair.second;
  }

  return 0;
}
