#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* createNode(int key) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(int key) {
    struct node *ptr, *ptr1, *newNode;
    newNode = createNode(key);
    if (root == NULL) {
        root = newNode;
        printf("\nNode inserted as root.\n");
        return;
    }
    ptr = root;
    ptr1 = NULL;
    while (ptr != NULL) {
        ptr1 = ptr;
        if (key < ptr->data)
            ptr = ptr->left;
        else if (key > ptr->data)
            ptr = ptr->right;
        else {
            printf("\nKey already exists. Insertion not possible.\n");
            free(newNode);
            return;
        }
    }
    if (key < ptr1->data)
        ptr1->left = newNode;
    else
        ptr1->right = newNode;
    printf("\nNode inserted.\n");
}

void preorder(struct node *ptr) {
    if (ptr != NULL) {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(struct node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(struct node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

struct node* succ(struct node *ptr) {
    struct node *ptr1 = ptr->right;
    while (ptr1->left != NULL)
        ptr1 = ptr1->left;
    return ptr1;
}

void deleteNode(struct node *root_ptr, int key) {
    struct node *parent, *ptr1, *ptr;
    int flag = 0, key1, call;
    if (root_ptr == NULL) {
        printf("Empty tree");
    } else {
        parent = NULL;
        ptr = root_ptr;
        while (ptr != NULL && flag == 0) {
            if (ptr->data > key) {
                parent = ptr;
                ptr = ptr->left;
            } else if (ptr->data < key) {
                parent = ptr;
                ptr = ptr->right;
            } else {
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("Item not found. Deletion not possible.");
            return;
        }
        if (ptr->left == NULL && ptr->right == NULL)
            call = 1;
        else if (ptr->left != NULL && ptr->right != NULL)
            call = 3;
        else
            call = 2;
        if (call == 1) {
            if (parent == NULL) {
                printf("Root deleted");
                root = NULL;
                return;
            }
            if (parent->left == ptr)
                parent->left = NULL;
            else
                parent->right = NULL;
        } else if (call == 2) {
            if (parent == NULL) {
                if (ptr->left == NULL)
                    root = ptr->right;
                else
                    root = ptr->left;
                return;
            }
            if (parent->left == ptr) {
                if (ptr->left == NULL)
                    parent->left = ptr->right;
                else
                    parent->left = ptr->left;
            } else {
                if (ptr->left == NULL)
                    parent->right = ptr->right;
                else
                    parent->right = ptr->left;
            }
        } else {
            ptr1 = succ(ptr);
            key1 = ptr1->data;
            deleteNode(root_ptr, key1);
            ptr->data = key1;
        }
    }
}

void main() {
    int choice, key;

    printf("\n***** AVL *****\n");
    printf("1. Insert Node\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Deletion\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &key);
                insertNode(key);
                break;
            case 2:
                printf("\nPreorder: ");
                preorder(root);
                break;
            case 3:
                printf("\nInorder: ");
                inorder(root);
                break;
            case 4:
                printf("\nPostorder: ");
                postorder(root);
                break;
            case 5:
                printf("\nEnter value to delete: ");
                scanf("%d", &key);
                deleteNode(root, key);
                break;
            case 6:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
}
