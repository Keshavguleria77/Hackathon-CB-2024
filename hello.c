#include <stdio.h>

#define SIZE 25

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0; // Not safe
        }
    }

    int startRow = row - row % 5;
    int startCol = col - col % 5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0; // Not safe
            }
        }
    }

    return 1; // Safe
}

int solveSudoku(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;

                        if (solveSudoku(grid)) {
                            return 1; // Solution found
                        }

                        grid[row][col] = 0;
                    }
                }

                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int grid[SIZE][SIZE] = {
        // Your initial Sudoku grid here
    };

    if (solveSudoku(grid)) {
        printf("Sudoku Solution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
