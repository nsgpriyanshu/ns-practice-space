#include <stdio.h>
#include <stdlib.h>

#define size 5

int DQ[size];
int front = -1, rear = -1;

void insertFront(int item) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front = front - 1;
    }
    DQ[front] = item;
    printf("%d inserted at front.\n", item);
    printf("Front = %d, Rear = %d\n", front, rear);
}

void insertRear(int item) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    DQ[rear] = item;
    printf("%d inserted at rear.\n", item);
    printf("Front = %d, Rear = %d\n", front, rear);
}

void deleteFront() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted from front: %d\n", DQ[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
    printf("Front = %d, Rear = %d\n", front, rear);
}

void deleteRear() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted from rear: %d\n", DQ[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear = rear - 1;
    }
    printf("Front = %d, Rear = %d\n", front, rear);
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    i = front;
    while (1) {
        printf("%d ", DQ[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
    printf("Front = %d, Rear = %d\n", front, rear);
}

int main() {
    int ch, item;

    while (1) {
        printf("\n---- DEQueue Menu ----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
