#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    prefixsum(arr, size);
    printf("\nprefix array");
    for (int i = 0; i < size; i++)
    {
        printf("\n%d ", arr[i]);
    }

    printf("%d ", arr[2]); // O(1)

    int start = 2;
    int end = 4;
    int result = rangesum(arr, start, end);
    printf("\n range from %d to %d is %d", start, end, result);
    return 0;
}
void prefixsum(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i]; // arr[2]=arr[1]+arr[2]  O(n)
    }
}
int rangesum(int arr[], int start, int end)
{
    if (start == 0)
        return end;
    else
        return arr[end] - arr[start - 1];
}