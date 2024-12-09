#include <stdio.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countsort(int arr[], int n, int exp)
{
    int arr1[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[j] / exp) % 10 == i)
            {
                arr1[index++] = arr[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr1[i];
    }
}

// void countSort(int arr[], int n, int exp)
// {
//     int output[n];
//     int count[10] = {0};

//     for (int i = 0; i < n; i++)
//         count[(arr[i] / exp) % 10]++;

//     for (int i = 1; i < 10; i++)
//         count[i] += count[i - 1];

//     for (int i = n - 1; i >= 0; i--)
//     {
//         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//         count[(arr[i] / exp) % 10]--;
//     }

//     for (int i = 0; i < n; i++)
//         arr[i] = output[i];
// }

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n); // int m=800

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countsort(arr, n, exp);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {170, 45, 800, 70, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);

    return 0;
}