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
│   ├── history.h              # Header for history module
│   ├── menu.h                 # Header for menu module
│   ├── operations.h           # Header for operations module
│   └── utils.h                # Header for utility functions
├── src/                       # Source code files
│   ├── history.c              # Handles operation history (save/load)
│   ├── main.c                 # Main program entry
│   ├── menu.c                 # Implements the main menu
│   ├── operations.c           # Performs mathematical operations
│   └── utils.c                # Utility functions
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

	•	C Programming Concepts:
	•	Modular programming with .h and .c files.
	•	File handling (fopen, fclose, fprintf, fscanf).
	•	Array and string manipulation.
	•	Dynamic memory management.
	•	Error Handling:
	•	Division by zero detection.
	•	Input validation for numbers and matrix dimensions.
	•	Build Automation:
	•	A Makefile is used to streamline the compilation process.

## License 📜

This project is licensed under the MIT License - see the LICENSE file for details.

Enjoy coding! 🎉
