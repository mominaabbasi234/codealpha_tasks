#include <iostream>
using namespace std;

int grid[9][9] =
{
    {3,0,6,5,0,8,4,0,0},
    {5,2,0,0,0,0,0,0,0},
    {0,8,7,0,0,0,0,3,1},
    {0,0,3,0,1,0,0,8,0},
    {9,0,0,8,6,3,0,0,5},
    {0,5,0,0,9,0,6,0,0},
    {1,3,0,0,0,0,2,5,0},
    {0,0,0,0,0,0,0,7,4},
    {0,0,5,2,0,6,3,0,0}
};

// Check if placing a number is valid
bool isSafe(int row, int col, int num)
{
    // Check row
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num)
            return false;

    // Check column
    for (int x = 0; x < 9; x++)
        if (grid[x][col] == num)
            return false;

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Solve Sudoku using Backtracking
bool solveSudoku()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(row, col, num))
                    {
                        grid[row][col] = num;

                        if (solveSudoku())
                            return true;

                        // Backtrack
                        grid[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

// Print Sudoku
void printGrid()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Original Sudoku:\n\n";
    printGrid();

    if (solveSudoku())
    {
        cout << "\nSolved Sudoku:\n\n";
        printGrid();
    }
    else
    {
        cout << "No Solution Exists!";
    }

    return 0;
}