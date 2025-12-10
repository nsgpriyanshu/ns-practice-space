#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

struct node *createNode(int key) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = key;
    n->left = n->right = NULL;
    return n;
}

void insertNode(int key) {
    struct node *p = root, *q = NULL, *n = createNode(key);
    if (root == NULL) {
        root = n;
        printf("\nNode inserted as root.");
        return;
    }
    while (p != NULL) {
        q = p;
        if (key < p->data)
            p = p->left;
        else if (key > p->data)
            p = p->right;
        else {
            printf("\nKey already exists. Insertion not possible.");
            free(n);
            return;
        }
    }
    if (key < q->data)
        q->left = n;
    else
        q->right = n;
    printf("\nNode inserted.");
}

void preorder(struct node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct node *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

void postorder(struct node *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

struct node *succ(struct node *p) {
    struct node *q = p->right;
    while (q->left != NULL)
        q = q->left;
    return q;
}

void deleteNode(struct node *r, int key) {
    struct node *par = NULL, *p = r, *q;
    int flag = 0, k, caseType;
    if (r == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    while (p != NULL && flag == 0) {
        if (key < p->data) {
            par = p;
            p = p->left;
        } else if (key > p->data) {
            par = p;
            p = p->right;
        } else
            flag = 1;
    }
    if (flag == 0) {
        printf("\nItem not found. Deletion not possible.");
        return;
    }
    if (p->left == NULL && p->right == NULL)
        caseType = 1;
    else if (p->left != NULL && p->right != NULL)
        caseType = 3;
    else
        caseType = 2;
    if (caseType == 1) {
        if (par == NULL) {
            printf("Root deleted.\n");
            root = NULL;
            return;
        }
        if (par->left == p)
            par->left = NULL;
        else
            par->right = NULL;
    } else if (caseType == 2) {
        struct node *child = (p->left != NULL) ? p->left : p->right;
        if (par == NULL) {
            root = child;
            return;
        }
        if (par->left == p)
            par->left = child;
        else
            par->right = child;
    } else {
        q = succ(p);
        k = q->data;
        deleteNode(r, k);
        p->data = k;
    }
}

void main() {
    int ch, key;
    printf("\n***** BST *****\n");
    printf("1. Insert Node\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Delete Node\n");
    printf("6. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &key);
                insertNode(key);
                break;
            case 2:
                printf("\nPreorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nInorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
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
