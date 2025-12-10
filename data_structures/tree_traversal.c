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
        printf("\nNode inserted as root.\n");
        return;
    }
    while (p != NULL) {
        q = p;
        if (key < p->data)
            p = p->left;
        else if (key > p->data)
            p = p->right;
        else {
            printf("\nKey already exists.\n");
            free(n);
            return;
        }
    }
    if (key < q->data)
        q->left = n;
    else
        q->right = n;
    printf("\nNode inserted.\n");
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

int height(struct node *p) {
    if (p == NULL)
        return 0;
    int lh = height(p->left);
    int rh = height(p->right);
    return (lh > rh ? lh : rh) + 1;
}

int countNodes(struct node *p) {
    if (p == NULL)
        return 0;
    return 1 + countNodes(p->left) + countNodes(p->right);
}

int getWidth(struct node *p, int level) {
    if (p == NULL)
        return 0;
    if (level == 1)
        return 1;
    return getWidth(p->left, level - 1) + getWidth(p->right, level - 1);
}

int maxWidth(struct node *p) {
    int h = height(p);
    int max = 0;
    for (int i = 1; i <= h; i++) {
        int w = getWidth(p, i);
        if (w > max)
            max = w;
    }
    return max;
}

int main() {
    int ch, key;

    printf("\n***** BINARY TREE MENU *****\n");
    printf("1. Insert Node\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Tree Height\n");
    printf("6. Tree Width\n");
    printf("7. Number of Nodes\n");
    printf("8. Exit\n");

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
                printf("\nHeight of tree: %d\n", height(root));
                break;
            case 6:
                printf("\nWidth of tree: %d\n", maxWidth(root));
                break;
            case 7:
                printf("\nTotal nodes: %d\n", countNodes(root));
                break;
            case 8:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}
