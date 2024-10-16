#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} Deque;

// Initialize the deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if the deque is full
int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));
}

// Check if the deque is empty
int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

// Insert at the front
void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = SIZE - 1;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = value;
    printf("Inserted %d at front\n", value);
}

// Insert at the rear
void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->rear == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = value;
    printf("Inserted %d at rear\n", value);
}

// Delete from the front
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted %d from front\n", dq->items[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

// Delete from the rear
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted %d from rear\n", dq->items[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = SIZE - 1;
    } else {
        dq->rear--;
    }
}

// Display the deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements are: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->items[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", dq->items[dq->rear]);
}

int main() {
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 30);
    insertFront(&dq, 40);

    display(&dq);

    deleteFront(&dq);
    deleteRear(&dq);

    display(&dq);

    return 0;
}

