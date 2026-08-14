#include<stdio.h>
#include<conio.h>

void main()
{
    int bt[20], wt[20], tat[20], pr[20], pid[20];
    int i, j, n, temp;
    float avgwt = 0, avgtat = 0;

    clrscr();

    printf("PRIORITY SCHEDULING (NON-PREEMPTIVE)\n");

    printf("\nEnter Number of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        pid[i]=i+1;

        printf("\nProcess P%d\n",pid[i]);

        printf("Burst Time : ");
        scanf("%d",&bt[i]);

        printf("Priority : ");
        scanf("%d",&pr[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j])
            {
                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }
        }
    }

    wt[0]=0;

    for(i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];

    for(i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\n\nGANTT CHART\n");

    printf("|");

    for(i=0;i<n;i++)
        printf(" P%d |",pid[i]);

    printf("\n0");

    temp=0;

    for(i=0;i<n;i++)
    {
        temp+=bt[i];
        printf("    %d",temp);
    }

    printf("\n\nProcess\tBT\tPriority\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
        pid[i],bt[i],pr[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);

    getch();
}