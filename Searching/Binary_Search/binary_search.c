#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // To avoid overflow

        // Check if the target is present at mid
        if (arr[mid] == target)
        {
            return mid; // Return the index if found
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main()
{
    int arr[] = {2, 3, 4, 5, 8}; // The array must be sorted for binary search
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}
