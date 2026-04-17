#include <stdio.h>
#include <conio.h>

#define INF 999

int n;
int cost[10][10];
int visited[10];
int minCost = INF;

void tsp(int city, int count, int currCost)
{
    int i;

    if(count == n && cost[city][0] > 0)
    {
        if(currCost + cost[city][0] < minCost)
            minCost = currCost + cost[city][0];
        return;
    }

    for(i=0;i<n;i++)
    {
        if(!visited[i] && cost[city][i])
        {
            visited[i] = 1;
            tsp(i, count+1, currCost + cost[city][i]);
            visited[i] = 0;
        }
    }
}

void main()
{
    int i,j;

    clrscr();

    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    for(i=0;i<n;i++)
        visited[i]=0;

    visited[0]=1;

    tsp(0,1,0);

    printf("Minimum cost = %d", minCost);

    getch();
}