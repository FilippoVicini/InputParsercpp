#include "inputOps.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> line;
  string fileName = "hello.txt";

  // call validateFile function
  validateFile(fileName);

  // call readFile function
  readFile(fileName, line);
}
