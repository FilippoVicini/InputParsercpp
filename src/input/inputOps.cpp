#include "inputOps.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Reads a file line by line and stores each line in a vector.
 *
 * @param  The name of the file to be read.
 * @param inputLines Vector where the file lines will be
 * stored.
 *
 *  */
void readFile(const string &fileName, vector<string> &inputLines) {
  string myText;

  ifstream in(fileName);
  while (getline(in, myText)) {
    // Add line to vector
    inputLines.push_back(myText);
  }
}

/**
 * Validates a file by checking its extension and existence.
 *
 * @param  The name of the file to validate.
 * @return True if the file has a valid extension and exists, false otherwise.
 *
 */
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

/**
 * Checks if a file has a ".txt" extension.
 *
 * @param The name of the file to check.
 * @return True if the file has a ".txt" extension, false otherwise.
 *
 * Finds the last occurrence of '.' and extracts the extension to
 * verify if it is "txt".
 */
bool checkFileName(const string &fileName) {
  // last occurrence of . in the file
  size_t pos = fileName.rfind('.');

  // If no '.' is found, there is no extension, so return false
  if (pos == string::npos)
    return false;

  // Extract the substring after the last '.' to get the file extension
  string ext = fileName.substr(pos + 1);

  if (ext == "txt")
    return true;

  return false;
}

/**
 * Checks if a file exists by attempting to open it.
 *
 * @param The name of the file to check.
 * @return True if the file can be opened, false otherwise.
 *
 */
bool checkFileExi(const string &fileName) {
  // Create an input file stream (ifstream) object to open the file
  ifstream file;

  file.open(fileName);

  if (!file) {
    // File doesn't exist
    cout << "File doesn't exist";
    return false;
  }
  return true;
}
