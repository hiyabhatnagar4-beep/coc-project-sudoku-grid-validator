// C Program for Suduko Validator
#include <stdio.h>

// Code to see if a 9-element array contains numbers 1-9 exactly once.
// It returns true if valid, and false if invalid.
int isValidUnit(int unit[9]) {
    int seen[10] = {0}; // An array to act as a checklist.

    for (int i = 0; i < 9; i++) {
        int num = unit[i];
        
        // To Check if the number in the valid range
        if (num < 1 || num > 9) {
            return 0; // Invalid number
        }
        
        if (seen[num] == 1) {
            return 0; // Invalid Number
        }
        
        // Mark this number as taken
        seen[num] = 1;
    }
    
    // all numbers 1-9 were present exactly once.
    return 1;
}

// to check that all rows contain numbers 1-9 exactly once.
int check_rows(int grid[9][9]) {
    printf("Checking rows...\n");
    for (int r = 0; r < 9; r++) {
        // grid[r] is a pointer to the r-th 9-element array.
        if (isValidUnit(grid[r]) == 0) {
            return 0; //Invalid row
        }
    }
    return 1; // All rows are valid
}

// to Check that all columns contain numbers 1-9 exactly once.
int check_columns(int grid[9][9]) {
    printf("Checking columns...\n");
    for (int c = 0; c < 9; c++) {
        //temporary 1D array for the column
        int column_unit[9];
        for (int r = 0; r < 9; r++) {
            column_unit[r] = grid[r][c];
        }
        
        if (isValidUnit(column_unit) == 0) {
            return 0; //invalid column
        }
    }
    return 1; // All columns are valid
}


//to check that all 3x3 subgrids contain numbers 1-9 exactly once.

int check_subgrids(int grid[9][9]) {
    printf("Checking subgrids...\n");
    
    // each 3x3 subgrid.
    for (int rowStart = 0; rowStart < 9; rowStart += 3) {
        for (int colStart = 0; colStart < 9; colStart += 3) {
            
            int subgrid_unit[9];
            int k = 0; // Index for our 1D subgrid_unit array

            for (int r = rowStart; r < rowStart + 3; r++) {
                for (int c = colStart; c < colStart + 3; c++) {
                    subgrid_unit[k] = grid[r][c];
                    k++;
                }
            }
            
            if (isValidUnit(subgrid_unit) == 0) {
                return 0; //invalid subgrid
            }
        }
    }
    return 1; // All subgrids are valid
}

int main() {
    // A hard-coded, valid Sudoku grid for testing
    int grid[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    
    // can test an INVALID grid by changing one number(any number).

    // Use if-else logic to check all three functions
    if (check_rows(grid) == 1 && 
        check_columns(grid) == 1 && 
        check_subgrids(grid) == 1) {
        
        // Final Output 
        printf("VALID SOLUTION\n");
    } else {
        printf("INVALID SOLUTION\n");
    }

    return 0;
}