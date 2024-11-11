#include "inputOps.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * readFile - Reads lines from a file and stores them in a vector
 * @param fileName: Name of file to read
 * @param inputLines: A reference to a vector of strings to store each line of
 * the input file
 *
 * Opens a file read each lines and pushes each line to a vector defined
 */
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

bool checkFileExi(const string &fileName) {
  // Create an input file stream (ifstream) object to open the file
  ifstream file;
  file.open(fileName);
  if (!file) {
    cout << "File doesn't exist";
    return false;
  }
  return true;
}
