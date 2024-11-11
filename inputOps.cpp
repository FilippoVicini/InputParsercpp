#include "inputOps.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to read file and push lines in vector
void readFile(const string &fileName, vector<string> &inputLines) {
  string myText;

  ifstream in(fileName);
  while (getline(in, myText)) { // Read each line into myText
    // Add line to input vector
    inputLines.push_back(myText);
    // Print the line to the console
    cout << myText << endl;
  }
}

// Function to handle different file errors
bool validateFile(const string &fileName) {
  // Check for correct file extension
  if (!checkFileName(fileName)) {
    cout << "Invalid file name";
    // Check if file exists
  } else if (!checkFileExi(fileName)) {
    cout << "File doesn't exist in program";
  }
  return true;
}

// Function to check if a file has a ".txt" extension
bool checkFileName(const string &fileName) {
  // last occurrence of . in the file
  size_t pos = fileName.rfind('.');

  // If no '.' is found, there is no extension, so return false
  if (pos == string::npos)
    return false;

  // Extract the substring after the last '.' to get the file extension
  string ext = fileName.substr(pos + 1);

  // Check if the extracted extension is "txt"
  if (ext == "txt")
    return true;

  // return false if not txt
  return false;
}

// Function to check if a file exists by attempting to open it
bool checkFileExi(const string &fileName) {
  // Create an input file stream (ifstream) object to open the file
  ifstream file;

  // Open file
  file.open(fileName);

  // If the file couldn't be opened
  if (!file) {
    // File doesn't exist
    cout << "File doesn't exist";
    return false;
  }
  // Return true when opened
  return true;
}
