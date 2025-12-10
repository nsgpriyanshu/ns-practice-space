#include <stdio.h>

#define SIZE 100
#define INF 32767

typedef struct {
    int u, v, w;
} Edge;

Edge edges[SIZE], resultK[SIZE];
int parent[SIZE];
int n, e;

int find(int v) {
    if (parent[v] == v)
        return v;
    return find(parent[v]);
}

void union_sets(int a, int b) {
    parent[a] = b;
}

void sort_edges() {
    int i, j;
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge t = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = t;
            }
        }
    }
}

void kruskal() {
    int i, count = 0, total = 0;
    sort_edges();

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < e && count < n - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);
        if (a != b) {
            resultK[count++] = edges[i];
            total += edges[i].w;
            union_sets(a, b);
        }
    }

    printf("\nEdges in MST (Kruskal):\n");
    for (i = 0; i < count; i++)
        printf("%d -- %d  weight %d\n", resultK[i].u, resultK[i].v, resultK[i].w);

    printf("Total cost: %d\n", total);
}

void prim() {
    int cost[SIZE][SIZE], visited[SIZE];
    int i, j, a = 0, b = 0, ne = 1, min, total = 0;

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    visited[1] = 1;

    printf("\nEdges in MST (Prim):\n");

    while (ne < n) {
        min = INF;

        for (i = 1; i <= n; i++) {
            if (visited[i] == 1) {
                for (j = 1; j <= n; j++) {
                    if (visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        visited[b] = 1;
        printf("Edge %d: (%d -> %d)  Cost = %d\n", ne, a, b, min);
        total += min;
        ne++;
    }

    printf("\nMinimum Cost = %d\n", total);
}

int main() {
    int choice, i;

    while (1) {
        printf("\n----- MST MENU -----\n");
        printf("1. Kruskal's Algorithm\n");
        printf("2. Prim's Algorithm\n");
        printf("3. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &n);

                printf("Enter number of edges: ");
                scanf("%d", &e);

                printf("Enter edges (u v w):\n");
                for (i = 0; i < e; i++)
                    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

                kruskal();
                break;

            case 2:
                printf("Enter number of vertices: ");
                scanf("%d", &n);
                prim();
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
