#include <stdio.h>

int insertion(int arr[], int size)
{
    int i, key, j;
    //[2,1,3,4,5,6,7]---> O(n) best case
    // average o(n^2)   --> []
    // sorted but reversed  [5,4,3,2,1]  ---> o(n2)
    for (i = 1; i < size; i++)
    {
        key = arr[i]; // key =9
        j = i - 1;    // j=1

        while (j >= 0 && arr[j] > key) // 5>9
        {
            // arr[1]=5
            arr[j + 1] = arr[j];
            j = j - 1; // 0-1
        }
        // arr[-1+1]=
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}