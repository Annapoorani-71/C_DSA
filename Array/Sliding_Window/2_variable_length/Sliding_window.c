#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to find maximum sum of a subarray with variable size
int maxSumVariableWindow(int arr[], int n, int maxSum)
{
    int current_sum = 0;
    int left = 0;
    int max_sum = 0;

    for (int right = 0; right < n; right++)
    {
        current_sum += arr[right]; // Add the rightmost element to the current sum

        // Shrink the window from the left if the current sum exceeds maxSum
        while (current_sum > maxSum && left <= right)
        {
            current_sum -= arr[left]; // Remove the leftmost element
            left++;                   // Move the left pointer to the right
        }

        // Update the maximum sum found so far
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int maxSum = 7; // Set maximum sum limit
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum sum of subarray with variable size: %d\n", maxSumVariableWindow(arr, n, maxSum));
    return 0;
}
