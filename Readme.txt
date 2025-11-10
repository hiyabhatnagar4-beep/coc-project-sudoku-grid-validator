Clash of Coders: Sudoku Grid Validator


Introduction: 
This is my capstone project for the "Clash of Coders" 6-day intensive training. The challenge was to build a program that could take a completed 9x9 Sudoku grid and figure out if it's a valid solution or not.




My program does this by reading a 9x9 grid (which is "hard-coded" into the main() function for testing ) and checking it against the three main rules of Sudoku.




It checks:


* That every row has the numbers 1-9, with no repeats.


* That every column has the numbers 1-9, with no repeats.


* All nine of the 3x3 sub-grids (or "boxes") also have the numbers 1-9, with no repeats.


* If all three of those checks pass, it prints "VALID SOLUTION". If even one of them fails, it prints "INVALID SOLUTION".


* Concepts We Used (as required by the guidelines)




C Programming (Day 1-6):


Functions: This was the most important part. I split the logic into separate functions: check_rows(), check_columns(), and the check_subgrids().


2D Arrays : The 9x9 Sudoku grid is stored in a int grid.


Nested Loops: Used these everywhere to iterate over the rows, columns, and especially inside the 3x3 sub-grids.


if-else : The main() function uses a simple if-else block to check what all the functions returned and print the final verdict.


Data Analysis: The main part was the logic for checking for duplicates. I created a helper function that uses a simple 10-element array (int seen[10]) as a "checklist" to track which numbers (1-9) it had already found in a row, column, or box. If it found a duplicate or a number outside the 1-9 range, the check would fail.




How to Compile and Run


1. Compile the code: Open your terminal and run this gcc command:


gcc sudoku_validator.c -o validator


2. Run the program: This will create an executable file named validator. Just run it from your terminal like this:


./validator
The program has a valid grid hard-coded in it, so it should print:


Checking rows...
Checking columns...
Checking subgrids...
VALID SOLUTION