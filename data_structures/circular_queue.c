#include <stdio.h>
#include <stdlib.h>

#define size 5

int CQ[size];
int front = -1, rear = -1;

void ENQ(int item) {
    int next;
    if (front == -1) {
        front = 0;
        rear = 0;
        CQ[rear] = item;
        printf("%d inserted in the queue.\n", CQ[rear]);
    } else {
        next = (rear + 1) % size;
        if (next == front) {
            printf("Overflow\n");
        } else {
            rear = next;
            CQ[rear] = item;
            printf("%d inserted in the queue.\n", CQ[rear]);
        }
    }
}

void DEQ() {
    int item;
    if (front == -1) {
        printf("Underflow\n");
    } else {
        item = CQ[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        printf("Deleted item: %d\n", item);
    }
}

void disp() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        i = front;
        while (1) {
            printf("%d ", CQ[i]);
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        printf("\n");
    }
}

void main() {
    int ch, item;

    while (1) {
        printf("\nPress 1: For ENQUEUE.\n");
        printf("Press 2: For DEQUEUE.\n");
        printf("Press 3: For DISPLAY.\n");
        printf("Press 4: For EXIT.\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value to insert:\n");
                scanf("%d", &item);
                ENQ(item);
                break;

            case 2:
                DEQ();
                break;

            case 3:
                disp();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}