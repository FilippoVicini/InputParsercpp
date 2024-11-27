#ifndef GUARD_inputOps_h
#define GUARD_inputOps_h

#include <vector>

//  Reads a file line by line and stores each line in a vector.
void readFile(const std::string &fileName,
              std::vector<std::string> &inputLines);

// Validates a file by checking its extension and existence.
bool validateFile(const std::string &fileName);

// Helper function to check if a file has a ".txt" extension.
bool checkFileName(const std::string &fileName);

// Helper function to check if a file exists by attempting to open it.
bool checkFileExi(const std::string &fileName);

#endif
