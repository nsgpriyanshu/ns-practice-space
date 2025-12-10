#include <stdio.h>
#include <stdlib.h>

#define INF 32676
#define SIZE 10

int n;
int w[SIZE][SIZE];
int d[SIZE];
int p[SIZE];
int visit[SIZE];

void INIT_SINGLE_SOURCE(int s) {
    int v;
    for (v = 0; v < n; v++) {
        d[v] = INF;
        p[v] = -1;
        visit[v] = 0;
    }
    d[s] = 0;
}

int EXTRACT_MIN() {
    int min = INF, u = -1, i;
    for (i = 0; i < n; i++) {
        if (!visit[i] && d[i] < min) {
            min = d[i];
            u = i;
        }
    }
    if (u != -1) {
        visit[u] = 1;
    }
    return u;
}

void RELAX(int u, int v) {
    if (w[u][v] != INF) {
        if (d[v] > d[u] + w[u][v]) {
            d[v] = d[u] + w[u][v];
            p[v] = u;
        }
    }
}

void DIJKSTRA_SSP(int s) {
    int u, v;
    INIT_SINGLE_SOURCE(s);

    while (1) {
        u = EXTRACT_MIN();
        if (u == -1)
            break;

        for (v = 0; v < n; v++) {
            if (w[u][v] != INF) {
                RELAX(u, v);
            }
        }
    }
}

void printPath(int v) {
    if (p[v] == -1) {
        printf("%d", v + 1);
        return;
    }
    printPath(p[v]);
    printf(" -> %d", v + 1);
}

int main() {
    int i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weight matrix (use %d for no edge):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
        }
    }

    printf("Enter source vertex (1 to %d): ", n);
    scanf("%d", &s);
    s--;

    DIJKSTRA_SSP(s);

    printf("\nShortest distances from source %d:\n", s + 1);
    for (i = 0; i < n; i++) {
        printf("%d -> %d : %d\n", s + 1, i + 1, d[i]);
    }

    printf("\nPaths:\n");
    for (i = 0; i < n; i++) {
        printf("%d -> %d : ", s + 1, i + 1);
        printPath(i);
        printf("\n");
    }

    return 0;
}
