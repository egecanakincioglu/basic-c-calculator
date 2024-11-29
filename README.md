# 🧮 Basic C Calculator

This project is a Basic Calculator built in C, designed for beginners who are exploring the fundamentals of C programming. It demonstrates modular programming, file handling, and basic arithmetic operations. The project includes functionalities for arithmetic operations, history tracking (stored in a CSV file), and a menu-driven user interface. 🚀

## Features ✨

	•	Arithmetic Operations:
	•	Addition ➕
	•	Subtraction ➖
	•	Multiplication ✖️
	•	Division ➗ (with zero division error handling)
	•	Square Root Calculation √
	•	Exponentiation a^b
	•	Matrix Addition 🧮
	•	History Tracking:
	•	Saves operation history in a data/history.csv file 📄
	•	Displays paginated history of operations for easy review 📜
	•	Menu-Driven Interface:
	•	User-friendly terminal interface for performing various tasks.
	•	Makefile Support:
	•	Simplified compilation process using a Makefile. 🛠️

## Project Structure 🗂️
```
basic-c-calculator/
├── build/                     # Build output directory
│   └── calculator             # Compiled executable
├── data/                      # Data storage folder
│   └── history.csv            # Stores calculation history
├── include/                   # Header files
│   ├── basic_operations.h     # Header for basic operations
│   ├── history.h              # Header for history module
│   ├── matrix_operations.h    # Header for matrix operations
│   ├── menu.h                 # Header for menu module
│   ├── operations.h           # Header for advanced operations module
│   └── utils.h                # Header for utility functions
├── src/                       # Source code files
│   ├── app/                   # Application-level code
│   │   ├── main.c             # Main program entry
│   │   └── menu.c             # Implements the main menu
│   ├── core/                  # Core functional modules
│   │   ├── basic_operations.c # Performs basic operations (e.g., +, -, *, /)
│   │   ├── history.c          # Handles operation history (save/load)
│   │   ├── matrix_operations.c # Handles matrix operations
│   │   ├── operations.c       # Performs advanced mathematical operations
│   │   └── utils.c            # Utility functions
├── .gitignore                 # Git ignore file
├── LICENSE                    # License file
├── Makefile                   # Build automation file
└── README.md                  # Documentation
```

## How to Run 🚀

### 1. Clone the Repository:
```
git clone https://github.com/egecanakincioglu/basic-c-calculator.git
cd basic-c-calculator
```

### 2. Compile the Program:
Use the included Makefile to compile the project.
```
make
```

### 3. Run the Program:
```
./build/calculator
```

### 4. Clean Build Files:
Remove compiled files using:
```
make clean
```

## Usage 🖥️

	•	Menu Options:
	•	Perform arithmetic operations like addition, subtraction, etc.
	•	View operation history stored in data/history.csv.
	•	Exit the application safely while saving all data.
	•	Paginated History:
	•	Scroll through saved operation history with navigation options.

## Highlights for Learning 📚
	
### C Programming Concepts
- **Modular Programming**: Code is divided into modules using `.h` and `.c` files.
- **File Handling**: Data recording and loading operations with `fopen`, `fclose`, `fprintf`, `fscanf`.
- **Array and String Manipulation**: Multidimensional arrays and string functions like `strcat` and `sprintf`.
- **Dynamic Memory Management**: Managing operation history using `malloc` and `free`.
- **Recursive Algorithms**: Used in operations like determinant calculation.
	
### Mathematical Operations
- **Basic Operations**: Fundamental mathematical functions such as addition, subtraction, multiplication, and division.
- **Advanced Operations**: Square root and exponentiation.
- **Matrix Operations**: Matrix addition, multiplication, and determinant calculation.
	
### Error Handling
- **Error Detection**:
- Division by zero check and user notification.
- Handling errors for square root of negative numbers.
- Error notifications for matrix dimension mismatch.
- **Input Validation**:
- Verifying that numerical inputs are positive and valid.
- Ensuring matrix dimensions are correct.
	
### Build Automation
- **Makefile Usage**:
- Simplifying the build process with commands like `make`, `make clean`, and `make run`.
- Optimized structure to compile only necessary changes in project files.
	
### Data Handling
- **Operation History Management**:
- Storing operation history in a linked list structure.
- Saving and reloading operation history to/from a CSV file.
	
### User Interaction
- **Menu-Based Structure**: Dynamically performing operations based on user input.
- **Result Visualization**: Clearly presenting results and operation history to the user after calculations.
	
### Programming Discipline
- Modular structure to enhance code readability.
- Managing user errors and ensuring secure input validation.
- Optimizing memory usage with dynamic data management.
	
This project is an ideal application for practicing both basic and advanced C programming concepts. Its modular structure and functional design provide a practical experience in developing systems for real-world problems.

## License 📜

This project is licensed under the MIT License.

Enjoy coding! 🎉
