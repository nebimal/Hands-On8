#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;  
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool Stack_Empty(Stack *s) {
    return s->top == -1;
}

bool Stack_Full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

bool push(Stack *s, int value) {
    if (Stack_Full(s)) {
        return false; // Stack overflow
    }
    s->data[++s->top] = value;
    return true;
}

bool pop(Stack *s, int *value) {
    if (Stack_Empty(s)) {
        return false; // Stack underflow
    }
    *value = s->data[s->top--];
    return true;
}

bool peek(Stack *s, int *value) {
    if (Stack_Empty(s)) {
        return false;
    }
    *value = s->data[s->top];
    return true;
}

int main(void){
    Stack s;
    initStack(&s);
    printf("Pushing elements onto the stack:\n");
    for (int i = 1; i <= MAX_SIZE; i++) {
        if (push(&s, i * 4)) {
            printf("Pushed: %d\n", i * 4);
        } 
    }
    int topValue;
    if (peek(&s, &topValue)) {
        printf("Current top (peek): %d\n", topValue);
    }
    
    printf("Stack (popped elements):\n");
    int value;
    while (pop(&s, &value)) {
        printf("%d\n", value);
    }
    if (!pop(&s, &value)) {
        printf("Stack is empty. Cannot pop further.\n");
    }
    
    return 0;
}