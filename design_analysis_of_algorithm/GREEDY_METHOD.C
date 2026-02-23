#include <stdio.h>
#include <conio.h>

void main()
{
    int n, i, j;
    float weight[20], profit[20], ratio[20];
    float W, temp;
    float total = 0;

    clrscr();

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i+1);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &W);

    for(i = 0; i < n; i++)
    {
        if(weight[i] <= W)
        {
            total += profit[i];
            W -= weight[i];
        }
        else
        {
            total += ratio[i] * W;
            break;
        }
    }

    printf("Maximum Profit = %.2f", total);

    getch();
}