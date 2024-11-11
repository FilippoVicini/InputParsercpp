#ifndef GUARD_stats_h
#define GUARD_stats_h

#include <vector>

// The readFile takes the file name as a parameter
// it returns a vector of strings where each string is a line in the file
void readFile(const std::string &fileName,
              std::vector<std::string> &inputLines);
bool validateFile(const std::string &fileName);
bool checkFileName(const std::string &fileName);
bool checkFileExi(const std::string &fileName);
#endif
