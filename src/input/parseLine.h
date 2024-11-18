#ifndef GUARD_parseLine_h
#define GUARD_parseLine_h
#include "../models/customer.h"
#include <unordered_map>
#include <vector>

// The readFile takes the file name as a parameter
// it returns a vector of strings where each string is a line in the file
void parseLine(const std::vector<std::string> &lines,
               std::unordered_map<std::string, Customer *> &customers);
bool validateFile(const std::string &fileName);
bool checkFileName(const std::string &fileName);
bool checkFileExi(const std::string &fileName);
#endif
