#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int top;
    int array[MAX];
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed\n", item);
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to pop\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Empty stack\n");
        return;
    }
    printf("Stack items: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initializeStack(&stack);
    int choice, value;

    while(1){
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                printStack(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
