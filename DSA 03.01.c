#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

// Initialize the queue
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return ((q->rear + 1) % SIZE == q->front);
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

// Add an element to the queue
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

// Remove an element from the queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    printf("Deleted %d\n", item);
    return item;
}

// Display the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", q->items[q->rear]);
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // Queue should be full now

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 60);

    display(&q);

    return 0;
}

