#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int front, rear;
    int items[MAX];
} Queue;

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue *queue) {
    return queue->rear == MAX - 1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full \n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = value;
    printf("%d is enqueued \n", value);
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty \n");
        return -1;
    }
    int item = queue->items[queue->front++];
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    printf("Dequeued item: %d\n", item);
    return item;
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty \n");
        return;
    }
    printf("Queue items: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initQueue(&queue);
    int choice, value;

    while(1){
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printQueue(&queue);
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
