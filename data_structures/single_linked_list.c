#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *header;

struct node* AllocateNode() {
    struct node *New;
    New = (struct node*)malloc(sizeof(struct node));
    return New;
}

void insert_front() {
    struct node *New;
    int key;
    New = AllocateNode();
    if (New == NULL) {
        printf("Error: Insufficient memory\n");
    } else {
        printf("Enter key for the node: ");
        scanf("%d", &key);
        New->link = header->link;
        header->link = New;
        New->data = key;
    }
}

void insert_last() {
    struct node *New;
    struct node *ptr;
    int key;
    New = AllocateNode();
    if (New == NULL) {
        printf("Error: Insufficient memory\n");
    } else {
        ptr = header;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        printf("Enter key for the last node: ");
        scanf("%d", &key);
        New->data = key;
        New->link = NULL;
        ptr->link = New;
    }
}

void insert_specific() {
    struct node *New;
    struct node *ptr;
    int key1, key2;
    New = AllocateNode();
    if (header->link == NULL) {
        printf("No node present in this list\n");
        exit(1);
    }
    if (New == NULL) {
        printf("Error: Insufficient memory\n");
    } else {
        printf("Enter the key1 to insert: ");
        scanf("%d", &key1);
        printf("Enter the key2 (after which to insert): ");
        scanf("%d", &key2);
        ptr = header->link;
        while (ptr->data != key2 && ptr->link != NULL) {
            ptr = ptr->link;
        }
        if (ptr->data == key2) {
            New->data = key1;
            New->link = ptr->link;
            ptr->link = New;
        } else {
            printf("Key2 not found, insertion not possible\n");
        }
    }
}

void delete_front() {
    struct node *ptr;
    if (header->link == NULL) {
        printf("Empty list, deletion not possible\n");
        exit(1);
    } else {
        printf("Node deleted from front\n");
        ptr = header->link;
        header->link = ptr->link;
        free(ptr);
    }
}

void delete_last() {
    struct node *ptr, *prev;
    if (header->link == NULL) {
        printf("Empty list, deletion not possible\n");
        exit(1);
    } else {
        printf("Node deleted from last\n");
        prev = header;
        ptr = header->link;
        while (ptr->link != NULL) {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        free(ptr);
    }
}

void delete_specific() {
    struct node *ptr, *prev;
    int key;
    if (header->link == NULL) {
        printf("Empty list, deletion not possible\n");
        exit(1);
    } else {
        printf("Enter the key to delete: ");
        scanf("%d", &key);
        prev = header;
        ptr = header->link;
        while (ptr->link != NULL && ptr->data != key) {
            prev = ptr;
            ptr = ptr->link;
        }
        if (ptr->data == key) {
            printf("Node deleted with key %d\n", key);
            prev->link = ptr->link;
            free(ptr);
        } else {
            printf("Key not found, deletion not possible\n");
        }
    }
}

void display() {
    struct node *ptr;
    ptr = header->link;
    printf("Linked list is:\n");
    printf("|   | %u |", header->link);
    while (ptr != NULL) {
        printf("--> | %d | %u |", ptr->data, ptr->link);
        ptr = ptr->link;
    }
}

void main() {
    int ch;
    header = (struct node*)malloc(sizeof(struct node));
    header->link = NULL;
    while (1) {
        printf("\nPress 1: For insertion at front\n");
        printf("Press 2: For insertion at last\n");
        printf("Press 3: For insertion at specific\n");
        printf("Press 4: For deletion at front\n");
        printf("Press 5: For deletion at last\n");
        printf("Press 6: For deletion at specific node\n");
        printf("Press 7: For display\n");
        printf("Press 8: For exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_front();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_specific();
                break;
            case 4:
                delete_front();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                delete_specific();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}