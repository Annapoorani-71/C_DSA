// code for segment tree to find minimum in a certain range
#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int rangeMinQuery(int segTree[], int qlow, int qhigh, int low, int high, int pos)
{
    // total overlap
    if (qlow <= low && qhigh >= high)
    {
        return segTree[pos];
    }
    // no overlap
    if (qlow > high || qhigh < low)
    {
        return INT_MAX;
    }
    // partial overlap
    int mid = (low + high) / 2;
    return min(rangeMinQuery(segTree, qlow, qhigh, low, mid, 2 * pos + 1), rangeMinQuery(segTree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
}

void constructTree(int arr[], int segTree[], int low, int high, int pos)
{
    if (low == high)
    {
        segTree[pos] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    constructTree(arr, segTree, low, mid, 2 * pos + 1);
    constructTree(arr, segTree, mid + 1, high, 2 * pos + 2);
    segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

int main()
{
    int arr[] = {-1, 2, 4, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int segTree[4 * n]; // 16
    constructTree(arr, segTree, 0, n - 1, 0);
    int result = rangeMinQuery(segTree, 1, 3, 0, n - 1, 0); //-1
    printf("Minimum value in range [1, 3]: %d\n", result);
    return 0;
}