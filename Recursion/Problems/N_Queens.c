#include <stdio.h>

#define N 4 // Change N for different board sizes

// Function to print the board
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place a queen at board[row][col]
int isSafe(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++) // Check left side
        if (board[row][i])
            return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // Upper diagonal
        if (board[i][j])
            return 0;

    for (int i = row, j = col; i < N && j >= 0; i++, j--) // Lower diagonal
        if (board[i][j])
            return 0;

    return 1;
}

// Recursive function to solve N-Queens
int solveNQueens(int board[N][N], int col)
{
    if (col >= N)
        return 1; // All queens placed  0>=4

    for (int i = 0; i < N; i++)
    { // 0
        if (isSafe(board, i, col))
        { // Place queen
            board[i][col] = 1;
            if (solveNQueens(board, col + 1))
                return 1;      // Recur for next column
            board[i][col] = 0; // Backtrack
        }
    }

    return 0; // No solution found
}

int main()
{
    int board[N][N] = {0};
    if (solveNQueens(board, 0))
        printSolution(board);
    else
        printf("Solution does not exist.\n");

    return 0;
}