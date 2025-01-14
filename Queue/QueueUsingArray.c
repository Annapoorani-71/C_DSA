#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
int data[MAX_SIZE];
int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
   return (q->front == -1 && q->rear == -1);
}

int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
    printf("Queue overflow!\n");
    return;
    }
    if (isEmpty(q)) {
    q->front = q->rear = 0;
    } else {
    q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->data[q->rear] = item;
}


int dequeue(Queue *q) {
        if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
        }
        int item = q->data[q->front];
        if (q->front == q->rear) {
        q->front = q->rear = -1;
        } else {
        q->front = (q->front + 1) % MAX_SIZE;
        }
        return item;
}


int main() 
{
    Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d\n", dequeue(&q)); // Output: 1
    printf("%d\n", dequeue(&q)); // Output: 2
    printf("%d\n", dequeue(&q)); // Output: 3
    return 0;
}