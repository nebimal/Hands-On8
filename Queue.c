#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];  
    int front;           
    int rear;          
    int size;            
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool Queue_Empty(Queue *q) {
    return (q->size == 0);
}

bool Queue_Full(Queue *q) {
    return (q->size == MAX_SIZE);
}

bool enqueue(Queue *q, int value) {
    if (Queue_Full(q)) {
        return false;  // Queue overflow
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
    return true;
}

bool dequeue(Queue *q, int *value) {
    if (Queue_Empty(q)) {
        return false;  // Queue underflow
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return true;
}

bool peekQueue(Queue *q, int *value) {
    if (Queue_Empty(q)) {
        return false;
    }
    *value = q->data[q->front];
    return true;
}

int main(void) {
    Queue q;
    initQueue(&q);
    
    printf("Enqueueing elements into the queue:\n");
    for (int i = 1; i <= MAX_SIZE; i++) {
        if (enqueue(&q, i * 15)) {
            printf("Enqueued: %d\n", i * 15);
        } else {
            printf("Failed to enqueue %d (Queue is full)\n", i * 15);
        }
    }
    
    int frontValue;
    if (peekQueue(&q, &frontValue)) {
        printf("Front element (peek): %d\n", frontValue);
    }
    
    printf("Queue (dequeued elements):\n");
    int value;
    while (dequeue(&q, &value)) {
        printf("%d\n", value);
    }
    
    if (!dequeue(&q, &value)) {
        printf("Queue is empty. Cannot dequeue further.\n");
    }    
    return 0;
}
