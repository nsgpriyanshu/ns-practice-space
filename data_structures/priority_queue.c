#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Element {
    int value;
    int priority;
};

struct Element PQ[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear == SIZE - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void insert(int value, int priority) {
    int i;
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }

    for (i = rear; i >= front && PQ[i].priority < priority; i--) {
        PQ[i + 1] = PQ[i];
    }

    PQ[i + 1].value = value;
    PQ[i + 1].priority = priority;
    rear++;

    printf("Inserted (Value=%d, Priority=%d).\n", value, priority);
    printf("Front = %d, Rear = %d\n", front, rear);
}

void delete() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted (Value=%d, Priority=%d)\n", PQ[front].value, PQ[front].priority);
    front++;

    if (front > rear) {
        front = rear = -1; // reset queue
    }
    printf("Front = %d, Rear = %d\n", front, rear);
}

void display() {
    if (front == -1) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("PQ       --> ");
    for (int i = front; i <= rear; i++) {
        printf("| %d ", PQ[i].value);
    }
    printf("|\n");

    printf("Priority --> ");
    for (int i = front; i <= rear; i++) {
        printf("| %d ", PQ[i].priority);
    }
    printf("|\n");

    printf("Front = %d, Rear = %d\n", front, rear);
}

void main() {
    int ch, value, priority;

    while (1) {
        printf("\n---- Priority Queue Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(value, priority);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
