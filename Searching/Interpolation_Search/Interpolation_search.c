#include <stdio.h>
int count = 0;
int interpolationSearch(int arr[], int low, int high, int x) // arr,0,14,18
{
    int pos;

    if (low <= high && x >= arr[low] && x <= arr[high])
    {
        count++;

        pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, high, x);

        if (arr[pos] > x)
            return interpolationSearch(arr, low, pos - 1, x);
    }
    return -1;
}

int main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
                 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 18; // Element to be searched
    int index = interpolationSearch(arr, 0, n - 1, x);

    // If element was found
    if (index != -1)
    {
        printf("Element found at index %d", index);
        printf("\n count= %d", count);
    }
    else
        printf("Element not found.");
    return 0;
}