#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

typedef struct RBNode {
    int data;
    enum Color color;
    struct RBNode *left, *right, *parent;
} RBNode;

RBNode* NIL = NULL;

RBNode* newNode(int data) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NIL;
    return node;
}

void leftRotate(RBNode **root, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != NIL)
        y->left->parent = x;
    y->parent = x->parent;

    if (x->parent == NIL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(RBNode **root, RBNode *x) {
    RBNode *y = x->left;
    x->left = y->right;
    if (y->right != NIL)
        y->right->parent = x;
    y->parent = x->parent;

    if (x->parent == NIL)
        *root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

void rbInsertFixup(RBNode **root, RBNode *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode *y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            RBNode *y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void rbInsert(RBNode **root, int data) {
    RBNode *z = newNode(data);
    RBNode *y = NIL;
    RBNode *x = *root;

    while (x != NIL) {
        y = x;
        if (data == x->data) {
            printf("Duplicate node %d not inserted.\n", data);
            free(z); 
            return;
        }
        else if (data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NIL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    z->left = z->right = NIL;
    z->color = RED;
    rbInsertFixup(root, z);
}

RBNode* treeMin(RBNode* x) {
    while (x->left != NIL)
        x = x->left;
    return x;
}

void rbTransplant(RBNode **root, RBNode *u, RBNode *v) {
    if (u->parent == NIL)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    v->parent = u->parent;
}

void rbDeleteFixup(RBNode **root, RBNode *x) {
    while (x != *root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBNode *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(root, x->parent);
                x = *root;
            }
        } else {
            RBNode *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    x->color = BLACK;
}

void rbDelete(RBNode **root, int data) {
    RBNode *z = *root;
    while (z != NIL && z->data != data) {
        if (data < z->data)
            z = z->left;
        else
            z = z->right;
    }

    if (z == NIL) {
        printf("Node %d not found!\n", data);
        return;
    }

    RBNode *y = z;
    enum Color y_orig_color = y->color;
    RBNode *x;

    if (z->left == NIL) {
        x = z->right;
        rbTransplant(root, z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        rbTransplant(root, z, z->left);
    } else {
        y = treeMin(z->right);
        y_orig_color = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else {
            rbTransplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rbTransplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);

    if (y_orig_color == BLACK)
        rbDeleteFixup(root, x);
}

void preorder(RBNode* root) {
    if (root != NIL) {
        printf("%d (%s) ", root->data, root->color == RED ? "R" : "B");
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    int choice, val;
    RBNode* root;

    NIL = (RBNode*)malloc(sizeof(RBNode));
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NULL;
    root = NIL;

    printf("\n--- Red-Black Tree Menu ---\n");
    printf("1. Insert Node\n");
    printf("2. Delete Node\n");
    printf("3. Display Tree (Preorder)\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            rbInsert(&root, val);
            printf("Node inserted successfully.\n");
        } 
        else if (choice == 2) {
            printf("Enter value to delete: ");
            scanf("%d", &val);
            rbDelete(&root, val);
        } 
        else if (choice == 3) {
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
        } 
        else if (choice == 4) {
            printf("Exiting program.\n");
            exit(0);
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
