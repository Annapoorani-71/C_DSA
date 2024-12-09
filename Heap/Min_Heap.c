#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct MinHeap
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

void initMinHeap(struct MinHeap *heap)
{
    heap->size = 0;
}

int getMin(struct MinHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap is empty!\n");
        return -1;
    }
    return heap->arr[0]; // Root element is the minimum
}

void insertMinHeap(struct MinHeap *heap, int value)
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
    while (i != 0 && heap->arr[i] < heap->arr[(i - 1) / 2])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapify(struct MinHeap *heap, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
    {
        smallest = left;
    }
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

int extractMin(struct MinHeap *heap)
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

    minHeapify(heap, 0);
    return root;
}

void decreaseKey(struct MinHeap *heap, int i, int newValue)
{
    heap->arr[i] = newValue;
    while (i != 0 && heap->arr[i] < heap->arr[(i - 1) / 2])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMinHeap(struct MinHeap *heap, int i)
{
    decreaseKey(heap, i, -100000); // Replace value with a very small value
    extractMin(heap);              // Remove the smallest value
}

void displayMinHeap(struct MinHeap *heap)
{
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct MinHeap heap;
    initMinHeap(&heap);

    insertMinHeap(&heap, 3);
    insertMinHeap(&heap, 1);
    insertMinHeap(&heap, 6);
    insertMinHeap(&heap, 5);
    insertMinHeap(&heap, 2);
    insertMinHeap(&heap, 4);

    printf("Min Heap: ");
    displayMinHeap(&heap);

    printf("Extracted min: %d\n", extractMin(&heap));
    printf("Min Heap after extraction: ");
    displayMinHeap(&heap);

    printf("Minimum value in heap: %d\n", getMin(&heap));

    decreaseKey(&heap, 2, 0); // Decrease the key at index 2 to 0
    printf("Min Heap after decreaseKey operation: ");
    displayMinHeap(&heap);

    deleteMinHeap(&heap, 1); // Delete key at index 1
    printf("Min Heap after delete operation: ");
    displayMinHeap(&heap);

    return 0;
}
