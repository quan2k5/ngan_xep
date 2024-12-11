#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    char array[MAX]; 
    int top;
} Stack;
void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}
void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Ngãn x?p ð?y.\n");
    } else {
        stack->array[++stack->top] = value;
    }
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngãn x?p r?ng.\n");
        return '\0'; 
    } else {
        return stack->array[stack->top--];
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);
    char input[MAX];
    char reversed[MAX];

    printf("Nh?p chu?i: ");
    fgets(input, MAX, stdin);
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    int i = 0;
    while (!isEmpty(&stack)) {
        reversed[i++] = pop(&stack);
    }
    reversed[i] = '\0'; 

    printf("Chu?i sau khi ð?o ngý?c: %s\n", reversed);

    return 0;
}

