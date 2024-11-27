#ifndef GUARD_parseLine_h
#define GUARD_parseLine_h
#include "../models/customer.h"
#include <sstream>
#include <unordered_map>
#include <vector>

// Parses transaction lines and updates customer data
void parseLine(const std::vector<std::string> &lines,
               std::unordered_map<std::string, Customer *> &customers);

#endif
