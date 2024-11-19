#ifndef GUARD_parseLine_h
#define GUARD_parseLine_h
#include "../models/customer.h"
#include <sstream>
#include <unordered_map>
#include <vector>

// The readFile takes the file name as a parameter
// it returns a vector of strings where each string is a line in the file
void parseLine(const std::vector<std::string> &lines,
               std::unordered_map<std::string, Customer *> &customers);
void lineValidation(std::istringstream line_s);
#endif
