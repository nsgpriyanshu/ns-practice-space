#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *head = NULL;

struct node* AllocateNode() {
    struct node *New;
    New = (struct node*)malloc(sizeof(struct node));
    return New;
}

void insert_front() {
    struct node *New, *ptr;
    int key;
    New = AllocateNode();
    if (New == NULL) {
        printf("Error: Insufficient memory\n");
    } else {
        printf("Enter key for the node: ");
        scanf("%d", &key);
        New->data = key;
        if (head == NULL) {
            head = New;
            New->link = head;
        } else {
            ptr = head;
            while (ptr->link != head) {
                ptr = ptr->link;
            }
            New->link = head;
            ptr->link = New;
            head = New;
        }
    }
}

void insert_last() {
    struct node *New, *ptr;
    int key;
    New = AllocateNode();
    if (New == NULL) {
        printf("Error: Insufficient memory\n");
    } else {
        printf("Enter key for the last node: ");
        scanf("%d", &key);
        New->data = key;
        if (head == NULL) {
            head = New;
            New->link = head;
        } else {
            ptr = head;
            while (ptr->link != head) {
                ptr = ptr->link;
            }
            ptr->link = New;
            New->link = head;
        }
    }
}

void insert_specific() {
    struct node *New, *ptr;
    int key1, key2;
    if (head == NULL) {
        printf("No node present in this list\n");
        return;
    }
    New = AllocateNode();
    if (New == NULL) {
        printf("Error: Insufficient memory\n");
    } else {
        printf("Enter the key1 to insert: ");
        scanf("%d", &key1);
        printf("Enter the key2 (after which to insert): ");
        scanf("%d", &key2);
        ptr = head;
        do {
            if (ptr->data == key2) {
                New->data = key1;
                New->link = ptr->link;
                ptr->link = New;
                return;
            }
            ptr = ptr->link;
        } while (ptr != head);
        printf("Key2 not found, insertion not possible\n");
    }
}

void delete_front() {
    struct node *ptr, *last;
    if (head == NULL) {
        printf("Empty list, deletion not possible\n");
        return;
    }
    if (head->link == head) {
        printf("Node deleted from front: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        ptr = head;
        last = head;
        while (last->link != head) {
            last = last->link;
        }
        printf("Node deleted from front: %d\n", head->data);
        head = head->link;
        last->link = head;
        free(ptr);
    }
}

void delete_last() {
    struct node *ptr, *prev;
    if (head == NULL) {
        printf("Empty list, deletion not possible\n");
        return;
    }
    if (head->link == head) {
        printf("Node deleted from last: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        ptr = head;
        while (ptr->link != head) {
            prev = ptr;
            ptr = ptr->link;
        }
        printf("Node deleted from last: %d\n", ptr->data);
        prev->link = head;
        free(ptr);
    }
}

void delete_after_specific() {
    struct node *ptr, *prev;
    int key;
    if (head == NULL) {
        printf("Empty list, deletion not possible\n");
        return;
    }
    printf("Enter the key (delete node after this): ");
    scanf("%d", &key);
    ptr = head;
    do {
        if (ptr->data == key) {
            prev = ptr->link;
            if (prev == head) {
                printf("Cannot delete head using this function\n");
                return;
            }
            printf("Node deleted after %d: %d\n", key, prev->data);
            ptr->link = prev->link;
            free(prev);
            return;
        }
        ptr = ptr->link;
    } while (ptr != head);
    printf("Key not found, deletion not possible\n");
}

void display() {
    struct node *ptr;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr = head;
    printf("Circular Linked List is:\n");
    do {
        printf("| %d | %u | -> ", ptr->data, ptr->link);
        ptr = ptr->link;
    } while (ptr != head);
    printf("(back to head)\n");
}

void main() {
    int ch;
    while (1) {
        printf("\nPress 1: Insert at front\n");
        printf("Press 2: Insert at last\n");
        printf("Press 3: Insert at specific\n");
        printf("Press 4: Delete at front\n");
        printf("Press 5: Delete at last\n");
        printf("Press 6: Delete after specific node\n");
        printf("Press 7: Display\n");
        printf("Press 8: Exit\n");
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
                delete_after_specific(); 
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
