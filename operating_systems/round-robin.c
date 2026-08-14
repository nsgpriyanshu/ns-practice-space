#include <stdio.h>
#include <conio.h>

void main()
{
    int bt[20], rem[20], wt[20], tat[20];
    int tempbt[20];
    int gantt[200];
    int n, tq;
    int i, done, time = 0;
    int gcount = 0;
    float avgwt = 0, avgtat = 0;

    clrscr();

    printf("ROUND ROBIN SCHEDULING\n");

    printf("\nEnter Number of Processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rem[i] = bt[i];
        tempbt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    do
    {
        done = 1;

        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                done = 0;
                gantt[gcount++] = i;

                if(rem[i] > tq)
                {
                    time += tq;
                    rem[i] -= tq;
                }
                else
                {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while(!done);

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\n\nGANTT CHART\n");

    printf("|");

    for(i = 0; i < gcount; i++)
        printf(" P%d |", gantt[i] + 1);

    printf("\n0");

    time = 0;

    for(i = 0; i < gcount; i++)
    {
        int p = gantt[i];

        if(tempbt[p] > tq)
        {
            tempbt[p] -= tq;
            time += tq;
        }
        else
        {
            time += tempbt[p];
            tempbt[p] = 0;
        }

        printf("    %d", time);
    }

    printf("\n\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f", avgtat / n);

    getch();
}