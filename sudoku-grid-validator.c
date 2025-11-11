// Sudoku validator in C

#include <stdio.h>

// Function to check if a given 9-element array has numbers 1 through 9, no repeats
int is_unit_valid(int arr[9]) {
    int seen[10] = {0};   // mark array (0 index unused)

    for (int i = 0; i < 9; ++i) {
        int val = arr[i];
        if (val < 1 || val > 9) {
            // number out of range
            return 0;
        }
        if (seen[val]) {
            // duplicate value found
            return 0;
        }
        seen[val] = 1;   // mark it as seen
    }

    // everything passed
    return 1;
}

// Checks each row of the Sudoku grid
int checkRows(int grid[9][9]) {
    printf("→ Checking rows now...\n");
    for (int r = 0; r < 9; r++) {
        // just pass the row directly
        if (!is_unit_valid(grid[r])) {
            printf("Row %d failed\n", r + 1);
            return 0;
        }
    }
    return 1;
}

// Checking each column.
int checkCols(int grid[9][9]) {
    printf("→ Checking columns...\n");
    for (int c = 0; c < 9; ++c) {
        int temp[9];
        for (int r = 0; r < 9; ++r) {
            temp[r] = grid[r][c];
        }

        if (!is_unit_valid(temp)) {
            printf("Column %d failed\n", c + 1);
            return 0;
        }
    }
    return 1;
}

//  creating the 3x3 subgrids
int checkBoxes(int grid[9][9]) {
    printf("→ Checking subgrids...\n");

    for (int rowBase = 0; rowBase < 9; rowBase += 3) {
        for (int colBase = 0; colBase < 9; colBase += 3) {
            int block[9];
            int idx = 0;

            for (int r = rowBase; r < rowBase + 3; ++r) {
                for (int c = colBase; c < colBase + 3; ++c) {
                    block[idx++] = grid[r][c];
                }
            }

            if (!is_unit_valid(block)) {
                printf("Subgrid starting at (%d,%d) failed\n", rowBase + 1, colBase + 1);
                return 0;
            }
        }
    }

    return 1;
}

int main(void) {

    // Hardcoding a valid Sudoku grid 
    int puzzle[9][9] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };


    int okRows = checkRows(puzzle);
    int okCols = checkCols(puzzle);
    int okBoxes = checkBoxes(puzzle);

    if (okRows && okCols && okBoxes) {
        printf("\n✅ VALID SUDOKU SOLUTION ✅\n");
    } else {
        printf("\n❌ INVALID SUDOKU ❌\n");
    }

    return 0;
}
