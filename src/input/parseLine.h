#ifndef GUARD_parseLine_h
#define GUARD_parseLine_h
#include "../models/customer.h"
#include <sstream>
#include <unordered_map>
#include <vector>

// Parses transaction lines and updates customer data
void parseLine(const std::vector<std::string> &lines,
               std::unordered_map<std::string, Customer *> &customers);

// Checks if all names in the people.txt file are consistent with the map
bool fileConsistency(std::unordered_map<std::string, Customer *> customers,
                     std::vector<std::string> people);

#endif
