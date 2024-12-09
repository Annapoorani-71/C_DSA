#include <stdio.h>
#define MAX 3
void prefixsum(int arr[MAX][MAX], int n, int m, int prefix[MAX][MAX])
{
    prefix[0][0] = arr[0][0];
    for (int i = 1; i < n; i++)
    {
        prefix[i][0] = prefix[i - 1][0] + arr[i][0];
    }
    for (int j = 1; j < m; j++)
    {
        prefix[0][j] = prefix[0][j - 1] + arr[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + arr[i][j] - prefix[i - 1][j - 1];
        }
    }
}
int main()
{
    int arr[MAX][MAX] = {{1, 5, 4}, {2, 0, 2}, {1, 3, 2}};
    int n = 3, m = 3;
    int prefix[3][3];
    prefixsum(arr, n, m, prefix);
    printf("original array\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\nprefix sum array\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", prefix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
