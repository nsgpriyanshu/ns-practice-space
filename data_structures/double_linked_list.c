#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL;

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
        New->data = key;
        New->prev = NULL;
        New->next = head;
        if (head != NULL) {
            head->prev = New;
        }
        head = New;
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
        New->next = NULL;
        if (head == NULL) {
            New->prev = NULL;
            head = New;
        } else {
            ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = New;
            New->prev = ptr;
        }
    }
}

void insert_after_specific() {
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
        printf("Enter the new value (key1): ");
        scanf("%d", &key1);
        printf("Enter the existing value (key2) after which to insert: ");
        scanf("%d", &key2);
        ptr = head;
        while (ptr != NULL) {
            if (ptr->data == key2) {
                New->data = key1;
                New->next = ptr->next;
                New->prev = ptr;
                if (ptr->next != NULL) {
                    ptr->next->prev = New;
                }
                ptr->next = New;
                printf("Inserted %d after %d\n", key1, key2);
                return;
            }
            ptr = ptr->next;
        }
        printf("Key %d not found, insertion not possible\n", key2);
    }
}

void delete_front() {
    struct node *ptr;
    if (head == NULL) {
        printf("Empty list, deletion not possible\n");
        return;
    }
    ptr = head;
    printf("Node deleted from front: %d\n", ptr->data);
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(ptr);
}

void delete_last() {
    struct node *ptr;
    if (head == NULL) {
        printf("Empty list, deletion not possible\n");
        return;
    }
    ptr = head;
    if (ptr->next == NULL) {
        printf("Node deleted from last: %d\n", ptr->data);
        free(ptr);
        head = NULL;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        printf("Node deleted from last: %d\n", ptr->data);
        ptr->prev->next = NULL;
        free(ptr);
    }
}

void delete_after_specific() {
    struct node *ptr, *temp;
    int key;
    if (head == NULL) {
        printf("Empty list, deletion not possible\n");
        return;
    }
    printf("Enter the key (delete node after this): ");
    scanf("%d", &key);
    ptr = head;
    while (ptr != NULL) {
        if (ptr->data == key && ptr->next != NULL) {
            temp = ptr->next;
            printf("Node deleted after %d: %d\n", key, temp->data);
            ptr->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = ptr;
            }
            free(temp);
            return;
        }
        ptr = ptr->next;
    }
    printf("Key not found or no node exists after it\n");
}

void display() {
    struct node *ptr;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr = head;
    printf("Doubly Linked List is:\n");
    while (ptr != NULL) {
        printf("| %u | %d | %u | <--> ", ptr->prev, ptr->data, ptr->next);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


void main() {
    int ch;
    while (1) {
        printf("\nPress 1: Insert at front\n");
        printf("Press 2: Insert at last\n");
        printf("Press 3: Insert after specific\n");
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
                insert_after_specific(); 
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
