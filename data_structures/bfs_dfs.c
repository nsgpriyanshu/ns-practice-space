#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define W 0
#define G 1
#define B 2

int graph[SIZE][SIZE];
int color[SIZE], parent[SIZE], distanceArr[SIZE];
int Q[SIZE];
int st[SIZE], ft[SIZE];
int f, r;
int timeCounter;

void ENQ(int x) {
    if (r == SIZE - 1) {
        return;
    }
    if (f == -1) {
        f = 0;
    }
    r++;
    Q[r] = x;
}

int DEQ() {
    int x;
    if (f == -1 || f > r) {
        return -1;
    }
    x = Q[f];
    f++;
    return x;
}

void BFS(int n, int s) {
    int u, v;

    for (v = 0; v < n; v++) {
        color[v] = W;
        distanceArr[v] = 9999;
        parent[v] = -1;
    }

    f = -1;
    r = -1;

    color[s] = G;
    distanceArr[s] = 0;
    parent[s] = -1;
    ENQ(s);

    printf("\nBFS Traversal:\n");

    while (f != -1 && f <= r) {
        u = DEQ();
        if (u == -1) {
            break;
        }

        printf("%d ", u);

        for (v = 0; v < n; v++) {
            if (graph[u][v] == 1 && color[v] == W) {
                color[v] = G;
                distanceArr[v] = distanceArr[u] + 1;
                parent[v] = u;
                ENQ(v);
            }
        }
        color[u] = B;
    }

    printf("\n\nVertex\tDistance\tParent");
    for (v = 0; v < n; v++) {
        printf("\n%d\t%d\t\t%d", v, distanceArr[v], parent[v]);
    }
}

void visit_DFS(int u, int n) {
    int v;

    color[u] = G;
    timeCounter++;
    st[u] = timeCounter;

    printf("%d ", u);

    for (v = 0; v < n; v++) {
        if (graph[u][v] == 1 && color[v] == W) {
            parent[v] = u;
            visit_DFS(v, n);
        }
    }

    color[u] = B;
    timeCounter++;
    ft[u] = timeCounter;
}

void DFS(int n) {
    int u;

    for (u = 0; u < n; u++) {
        color[u] = W;
        parent[u] = -1;
    }

    timeCounter = 0;

    printf("\nDFS Traversal:\n");

    for (u = 0; u < n; u++) {
        if (color[u] == W) {
            visit_DFS(u, n);
        }
    }

    printf("\n\nVertex\tStart\tFinish\tParent");
    for (u = 0; u < n; u++) {
        printf("\n%d\t%d\t%d\t%d", u, st[u], ft[u], parent[u]);
    }
}

int main() {
    int n, i, j, s, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    while (1) {
        printf("\n---- Graph Traversal Menu ----\n");
        printf("1. BFS (Breadth First Search)\n");
        printf("2. DFS (Depth First Search)\n");
        printf("3. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter source vertex (0 to %d): ", n - 1);
                scanf("%d", &s);

                if (s < 0 || s >= n) {
                    printf("\nInvalid source vertex!");
                } else {
                    BFS(n, s);
                }
                break;

            case 2:
                DFS(n);
                break;

            case 3:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }

        printf("\n\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}
