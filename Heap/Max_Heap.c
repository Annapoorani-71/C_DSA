#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct MaxHeap
{
    int arr[MAX];
    int size;
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void initMaxHeap(struct MaxHeap *heap)
{
    heap->size = 0;
}

int getMax(struct MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap is empty!\n");
        return -1;
    }
    return heap->arr[0]; // Root element is the maximum
}

void insertMaxHeap(struct MaxHeap *heap, int value)
{
    if (heap->size >= MAX)
    {
        printf("Heap is full!\n");
        return;
    }
    heap->arr[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // Heapify up
    while (i != 0 && heap->arr[i] > heap->arr[(i - 1) / 2])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapify(struct MaxHeap *heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
    {
        largest = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&heap->arr[i], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

int extractMax(struct MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap is empty!\n");
        return -1;
    }
    if (heap->size == 1)
    {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    maxHeapify(heap, 0);
    return root;
}

void increaseKey(struct MaxHeap *heap, int i, int newValue)
{
    heap->arr[i] = newValue;
    while (i != 0 && heap->arr[i] > heap->arr[(i - 1) / 2])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMaxHeap(struct MaxHeap *heap, int i)
{
    increaseKey(heap, i, 100000); // Replace value with a very large value
    extractMax(heap);             // Remove the largest value
}

void displayMaxHeap(struct MaxHeap *heap)
{
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct MaxHeap heap;
    initMaxHeap(&heap);

    insertMaxHeap(&heap, 3);
    insertMaxHeap(&heap, 1);
    insertMaxHeap(&heap, 6);
    insertMaxHeap(&heap, 5);
    insertMaxHeap(&heap, 2);
    insertMaxHeap(&heap, 4);

    printf("Max Heap: ");
    displayMaxHeap(&heap);

    printf("Extracted max: %d\n", extractMax(&heap));
    printf("Max Heap after extraction: ");
    displayMaxHeap(&heap);

    printf("Maximum value in heap: %d\n", getMax(&heap));

    increaseKey(&heap, 2, 10); // Increase the key at index 2 to 10
    printf("Max Heap after increaseKey operation: ");
    displayMaxHeap(&heap);

    deleteMaxHeap(&heap, 1); // Delete key at index 1
    printf("Max Heap after delete operation: ");
    displayMaxHeap(&heap);

    return 0;
}
