#include <stdio.h>
 
// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Partition function to place pivot element in the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = (low - 1);      // Index of smaller element
 
    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);  // Swap elements
        }
    }
 
    swap(&arr[i + 1], &arr[high]);  // Place pivot in the correct position
    return (i + 1);
}
 
// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);
 
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Original array: \n");
    printArray(arr, n);
 
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
 
    return 0;
}