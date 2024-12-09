#include <stdio.h>
#include <stdlib.h>

void count(int arr[], int size)
{
    // finding the max
    int max = arr[0]; // 9
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    //[1]
    //[0,0,1,0,0,2,1,0,0,1]
    int *freq = calloc(max + 1, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (freq[i] != 0) // 1!=0
        {
            arr[index] = i;
            index++;
            freq[i]--;
        }
    }
}
int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    count(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}