#include <stdio.h>
#include <conio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

void main()
{
    int n, i, w;
    int weight[20], profit[20];
    int W;
    int dp[20][20];

    clrscr();

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter weight and profit of item %d: ", i);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weight[i] <= w)
                dp[i][w] = max(profit[i] + dp[i-1][w-weight[i]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("Maximum Profit = %d", dp[n][W]);

    getch();
}