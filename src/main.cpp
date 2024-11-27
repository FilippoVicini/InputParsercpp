#include "./input/inputOps.h"
#include "./input/parseLine.h"
#include "./models/customer.h"
#include "./models/product.h"
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

  // people contained in the people.txt with trim
  unordered_set<string> peopleSet;
  for (const string &person : people) {
    // Trim
    size_t first = person.find_first_not_of(" \t\n\r");
    size_t last = person.find_last_not_of(" \t\n\r");
    if (first != string::npos && last != string::npos) {
      peopleSet.insert(person.substr(first, (last - first + 1)));
    }
  }
  // Iterate through map and return only customers in the peopleSet
  for (const auto &pair : customers) {
    // Check if the customer is in the people.txt list
    if (peopleSet.find(pair.first) != peopleSet.end()) {
      cout << pair.first << endl;

      double totalSpent = 0;
      for (const auto &product : pair.second->getProducts()) {
        cout << product.getName() << " " << product.getPrice() << endl;
        totalSpent += product.getPrice();
      }

      cout << "Total: " << totalSpent << endl << endl;
    }
  }

  return 0;
}
