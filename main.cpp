#include "inputOps.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> line;
  validateFile("hello.txt");
  readFile("payments.txt", line);
  for (int i = 0; i < line.size(); i++) {
    cout << "mytest" << line[i] << endl;
  }
}
