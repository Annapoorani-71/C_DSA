#include <stdio.h>

int kadaen(int arr[], int size)
{
    int current_max = arr[0];
    int global_max = arr[0];
    for (int i = 1; i < size; i++)
    {
        current_max = (arr[i] > (current_max + arr[i])) ? arr[i] : current_max + arr[i];
        if (current_max > global_max)
        {
            global_max = current_max;
        }
    }
    return global_max;
}

int main()
{
    int arr[] = {-2, 3, 2, -1};
    int size = (sizeof(arr) / sizeof(arr[0]));

    int data = kadaen(arr, size);

    printf("%d", data);
    return 0;
}
