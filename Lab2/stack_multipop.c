#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int data[MAX];
    int top;
    int operationCount;
} Stack;

void initialize(Stack *S) {
    S->top = -1;
    S->operationCount = 0;
}

int isEmpty(Stack *S) {
    return S->top == -1;
}

int isFull(Stack *S) {
    return S->top == MAX - 1;
}

void push(Stack *S, int x) {
    if (isFull(S)) {
        printf("Stack overflow\n");
        return;
    }
    S->data[++S->top] = x;
    S->operationCount++;
}

int pop(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack underflow\n");
        return -1;
    }
    S->operationCount++;
    return S->data[S->top--];
}

void Multipop(Stack *S, int k) {
    for (int i = 0; i < k && !isEmpty(S); i++) {
        pop(S);
    }
}

void printStack(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack items: ");
    for (int i = 0; i <= S->top; i++) {
        printf("%d ", S->data[i]);
    }
    printf("\n");
}

void printAmortizedCost(Stack *S, int totalOperations) {
    if (totalOperations == 0) {
        printf("No operations performed yet\n");
        return;
    }
    double amortizedCost = (double) S->operationCount / totalOperations;
    printf("No of operations: %d\n", totalOperations);
    printf("Amortized cost per operation: %.2f\n", amortizedCost);
}

int main() {
    Stack S;
    initialize(&S);

    int choice, item, k;
    int totalOperations = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Multipop\n");
        printf("4. Print Stack\n");
        printf("5. Print Amortized Cost\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(&S, item);
                totalOperations++;
                break;

            case 2:
                pop(&S);
                totalOperations++;
                break;

            case 3:
                printf("Enter number of elements to multipop: ");
                scanf("%d", &k);
                Multipop(&S, k);
                totalOperations += k;
                break;

            case 4:
                printStack(&S);
                break;

            case 5:
                printAmortizedCost(&S, totalOperations);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
