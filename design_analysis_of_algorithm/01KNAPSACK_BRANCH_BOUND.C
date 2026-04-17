#include <stdio.h>
#include <conio.h>

int n, W;
int p[10], w[10];
float maxProfit = 0;

float bound(int i, int weight, int profit)
{
    int j;
    float b = profit;

    while(i <= n && weight + w[i] <= W)
    {
        weight += w[i];
        b += p[i];
        i++;
    }

    if(i <= n)
        b += (W - weight) * (float)p[i]/w[i];

    return b;
}

void knapsack(int i, int profit, int weight)
{
    if(weight <= W && profit > maxProfit)
        maxProfit = profit;

    if(bound(i+1, weight, profit) > maxProfit)
    {
        if(weight + w[i+1] <= W)
            knapsack(i+1, profit + p[i+1], weight + w[i+1]);

        knapsack(i+1, profit, weight);
    }
}

void main()
{
    int i;

    clrscr();

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter profits:\n");
    for(i=1;i<=n;i++) scanf("%d",&p[i]);

    printf("Enter weights:\n");
    for(i=1;i<=n;i++) scanf("%d",&w[i]);

    printf("Enter capacity: ");
    scanf("%d",&W);

    knapsack(0,0,0);

    printf("Max Profit = %.0f", maxProfit);

    getch();
}