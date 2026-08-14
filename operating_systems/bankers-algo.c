#include <stdio.h>
#include <conio.h>

void main()
{
    int n, m;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], work[10], finish[10];
    int safeSeq[10];
    int i, j, k, count = 0;
    int found;

    clrscr();

    printf("BANKER'S ALGORITHM\n");
    printf("------------------\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    /* Input Allocation Matrix */
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    /* Input Maximum Matrix */
    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    /* Input Available Resources */
    printf("\nEnter Available Resources:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    /* Calculate Need Matrix */
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    /* Initialize Work and Finish */
    for(j = 0; j < m; j++)
        work[j] = avail[j];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    /* Banker's Algorithm */
    while(count < n)
    {
        found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                        break;
                }

                if(j == m)
                {
                    /* Process can finish */
                    for(k = 0; k < m; k++)
                        work[k] = work[k] + alloc[i][k];

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    /* Display Need Matrix */
    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    /* Check Safe State */
    if(count == n)
    {
        printf("\nSystem is in SAFE STATE.\n");

        printf("Safe Sequence: ");
        for(i = 0; i < n; i++)
        {
            printf("P%d", safeSeq[i]);

            if(i != n - 1)
                printf(" -> ");
        }
    }
    else
    {
        printf("\nSystem is in UNSAFE STATE.");
        printf("\nNo safe sequence exists.");
    }

    getch();
}