#include<stdio.h>
#include<conio.h>

void main() {
    int bt[20], wt[20], tat[20], p[20];
    int n, i, j, temp;
    float awt = 0, atat = 0;

    clrscr();

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nSJF Gantt Chart\n\n");

    printf("|");
    for(i = 0; i < n; i++)
        printf(" P%d |", p[i]);

    printf("\n0");
    for(i = 0; i < n; i++)
        printf(" %d", tat[i]);

    printf("\n\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f", atat / n);

    getch();
}