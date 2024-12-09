#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char direction[] = "DLRU";

int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};

int isValid(int row, int col, int n, int maze[4][4])
{
    return row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1;
}

void findPath(int row, int col, int maze[4][4], int n, char **ans, int *ansSize, char *currentPath, int pathIndex)
{

    if (row == n - 1 && col == n - 1)
    {
        currentPath[pathIndex] = '\0';
        ans[*ansSize] = (char *)malloc((pathIndex + 1) * sizeof(char));
        strcpy(ans[*ansSize], currentPath);
        (*ansSize)++;
        return;
    }

    maze[row][col] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];

        if (isValid(nextRow, nextCol, n, maze))
        {
            currentPath[pathIndex] = direction[i];
            findPath(nextRow, nextCol, maze, n, ans, ansSize, currentPath, pathIndex + 1);
        }
    }
    maze[row][col] = 1;
}

int main()
{

    int maze[4][4] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {1, 1, 0, 0},
                      {0, 1, 1, 1}};

    int n = 4;

    char *result[100];
    int resultSize = 0;

    char currentPath[100];

    if (maze[0][0] != 0 && maze[n - 1][n - 1] != 0)
    {

        findPath(0, 0, maze, n, result, &resultSize, currentPath, 0);
    }
    if (resultSize == 0)
    {
        printf("-1\n");
    }
    else
    {
        for (int i = 0; i < resultSize; i++)
        {
            printf("%s ", result[i]);
            free(result[i]);
        }
        printf("\n");
    }

    return 0;
}
