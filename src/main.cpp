#include "customer.h"
#include "inputOps.h"
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;
void parseLine(const string &line, unordered_map<string, Customer>);
int main() {
  vector<string> line;
  unordered_map<string, Customer> customers;
  string fileName = "payments.txt";

  // call validateFile function
  validateFile(fileName);

  // call readFile function
  readFile(fileName, line);
  for (int i = 0; i < line.size(); i++) {
    cout << line[i];
  }
}

void parseLine(const string &line, unordered_map<string, Customer> customers) {}

// the vector line is a vector containing all the lines in the file
// eg. Bill egg 3.5
//     jonny egg 6
// the parseLine will get the line and split the name, item and price
// I then want to add the customers in the unordered map
