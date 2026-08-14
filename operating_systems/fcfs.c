#include<stdio.h>
#include<conio.h>

void main() {
    int bt[20], wt[20], tat[20];
    int n, i;
    float awt = 0, atat = 0;

    clrscr();

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    /* Gantt Chart */
    printf("\n\nFCFS Gantt Chart\n\n");

    printf(" ");

    for(i = 0; i < n; i++)
        printf("-------");

    printf("-\n|");

    for(i = 0; i < n; i++)
        printf(" P%d  |", i + 1);

    printf("\n ");

    for(i = 0; i < n; i++)
        printf("-------");

    printf("-\n");

    printf("0");

    for(i = 0; i < n; i++)
        printf("%7d", tat[i]);

    printf("\n");

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time    = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f", atat / n);

    getch();
}