# InputParserCPP

My IN2029 coursework for City University 2024 Computer Science

## Task

The file payments.txt contains a simple textual table. Each line lists three pieces of
information: a person's name, an object name, and the price of the object purchased by the person,
separated by one space, e.g.:

```
Bob eggs 2.5
Alice apple 1.5
Ava pen 2
Bob pen 3.5
Alice eggs 2
```

The expected return for the sample file should be:

```
Bob
eggs 2.5
pen 3.5
Total: 6
Alice
apple 1.5
eggs 2
Total: 3.5
```

## Stack
### Prerequisites
    - C++ Compiler: Ensure you have a C++ compiler installed:
        For macOS: clang++
        For Windows: MinGW or MSVC (Microsoft Visual Studio)
    - CMake: Version 3.10 or higher.
### Folder Structure
```
coursework1/
├── build/              # Build directory (generated during compilation)
├── src/                # Source files
│   ├── main.cpp        # Main program file
│   ├── inputOps.cpp    # Handles file operations
│   ├── customer.cpp    # Handles customer-specific logic
│   ├── product.cpp     # Handles product-related logic
│   └── ...
├── include/            # Header files
│   ├── inputOps.h      # Declarations for input operations
│   ├── customer.h      # Declarations for customer logic
│   ├── product.h       # Declarations for product logic
│   └── ...
├── payments.txt        # Input file containing the list of purchases
├── CMakeLists.txt      # CMake configuration file
└── README.md           # Documentation file
```

### Build and Run Instructions
#### Clone the repo 
```
git clone <repository_url>
cd coursework1
```
#### Run Cmake
```
cmake ..
```
#### Compile the code
```
make
```
#### Run the program
```
./coursework1
```
