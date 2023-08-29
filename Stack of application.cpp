#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element.\n");
        return '\0'; 
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    char input[MAX_SIZE];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    printf("Reversed string: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    
    printf("\n");

    return 0;
}
