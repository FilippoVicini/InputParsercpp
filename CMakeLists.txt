
cmake_minimum_required(VERSION 3.10)

# Project name
project(coursework1)

# Specify the C++ standard (optional)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable

add_executable(coursework1 
    src/main.cpp 
    src/inputOps.cpp 
    src/customer.cpp 
    src/product.cpp
)


# Include directories (if using headers)
include_directories(include)
