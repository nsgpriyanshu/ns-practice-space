#include <stdio.h>
#include <conio.h>

#define SIZE 10

struct Edge {
    int src;
    int dest;
    int weight;
};

int parent[SIZE];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void Union(int x, int y)
{
    parent[x] = y;
}

void sortEdges(struct Edge edges[], int E)
{
    int i, j;
    struct Edge temp;

    for(i = 0; i < E-1; i++)
    {
        for(j = 0; j < E-i-1; j++)
        {
            if(edges[j].weight > edges[j+1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

void Kruskal(struct Edge edges[], int V, int E)
{
    int i;
    int count = 0;

    sortEdges(edges, E);

    for(i = 0; i < V; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    for(i = 0; i < E && count < V-1; i++)
    {
        int u = find(edges[i].src);
        int v = find(edges[i].dest);

        if(u != v)
        {
            printf("%d -- %d == %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            Union(u, v);
            count++;
        }
    }
}

void main()
{
    int V = 4;
    int E = 5;

    struct Edge edges[5] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    clrscr();

    Kruskal(edges, V, E);

    getch();
}