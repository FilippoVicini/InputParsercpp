cmake_minimum_required(VERSION 3.10)
project(coursework1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(coursework1
    src/main.cpp
    src/input/inputOps.cpp
    src/input/parseLine.cpp
    src/models/customer.cpp
    src/models/product.cpp
)

# Include directories
include_directories(src)
